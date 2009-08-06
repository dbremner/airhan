using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Text;

namespace ZIPViewer
{
    class ZipArchive
    {
        private String m_fileName;
        private FileStream m_fStream = null;
        private List<ZipCentralDirFileHeader> m_zipEntryNameList = new List<ZipCentralDirFileHeader>();
        private ZipEndCentralDir m_zipEndCentralDir = new ZipEndCentralDir();

        public List<ZipCentralDirFileHeader> ZipItemList
        {
            get
            {
                return m_zipEntryNameList;
            }
        }
        public ZipEndCentralDir ZipEndOfCentralDirectoryRecord
        {
            get
            {
                return m_zipEndCentralDir;
            }
        }

        public ZipArchive()
        {
            m_fileName = "";
        }

        public ZipArchive(String zipArchiveName)
        {
            m_fileName = zipArchiveName;
        }

        public void LoadZipMetaData()
        {
            if (String.IsNullOrEmpty(m_fileName))
            {
                throw new ApplicationException("Zip archive name is empty");
            }

            try
            {
                m_fStream = new FileStream(m_fileName, FileMode.Open, FileAccess.Read);
                long size = m_fStream.Length;
                //At least we need a 4 bytes headers (regardless of what header it is), isn't it
                if (size <= 4)
                {
                    throw new ApplicationException(m_fileName + " is not a valid zip archive because its size is only " + size + " bytes");
                }

                Byte[] buff = new Byte[size];

                m_fStream.Read(buff, 0, (int)size);

                ReadCentralDirectory(buff);
                ReadEndOfCentralDirectory(buff);
            }
            catch (Exception exc)
            {
                throw exc;
            }
            finally
            {
                if (m_fStream != null)
                {
                    m_fStream.Close();
                    m_fStream = null;
                }
            }
        }

        private void ReadCentralDirectory(Byte[] buffer)
        {
            int bufferLength = buffer.Length;
            if (bufferLength <= 4)
            {
                throw new ArgumentException("Buffer size is too small. A buffer containing central directory must at least greater than 4bytes");
            }

            int index = 0;
            bool found = false;
            int unReadBytesCount = bufferLength;

            while (unReadBytesCount != 0)
            {
                //Reached the boundary and not found central directory
                if (index > bufferLength - 4)
                {
                    break;
                }

                found = (buffer[index] == 0x50) && (buffer[index + 1] == 0X4B) && (buffer[index + 2] == 0x01) && (buffer[index + 3] == 0x02);

                if (found)
                {
                    break;
                }

                index++;
                unReadBytesCount--;
            }

            int currentIndex = index;

            if (found)
            {
                //Read Central Directory File Headers and build file naming list
                for (; ; )
                {
                    ZipCentralDirFileHeader cFHeader = new ZipCentralDirFileHeader();
                    cFHeader.Signature = readBytes(buffer, currentIndex, 4);
                    currentIndex = currentIndex + 4;
                    bool isValidSignature = (cFHeader.Signature[0] == 0x50) && (cFHeader.Signature[1] == 0x4B) && (cFHeader.Signature[2] == 0x01) && (cFHeader.Signature[3] == 0x02);

                    //No more central dir file headers to read
                    if (isValidSignature == false)
                    {
                        break;
                    }

                    #region Load Central Directory File Header Fields
                    cFHeader.VersionMadeBy = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.VersionNeedToExtract = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.BitFlag = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.CompressionMethod = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.LastModifyTime = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.LastModifyDate = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.CRC32 = readBytes(buffer, currentIndex, 4);
                    currentIndex += 4;

                    cFHeader.CompressedSize = readBytes(buffer, currentIndex, 4);
                    currentIndex += 4;

                    cFHeader.UncompressedSize = readBytes(buffer, currentIndex, 4);
                    currentIndex += 4;

                    cFHeader.FileNameLength = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.ExtraFieldLength = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.FileCommentLength = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.DiskNumberStart = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.InternalFileAttributes = readBytes(buffer, currentIndex, 2);
                    currentIndex += 2;

                    cFHeader.ExternalFileAttributes = readBytes(buffer, currentIndex, 4);
                    currentIndex += 4;

                    cFHeader.OffSetOfLocalFileHeader = readBytes(buffer, currentIndex, 4);
                    currentIndex += 4;

                    //Load file name
                    int fileLength = ((int)cFHeader.FileNameLength[1]) * 256 + (int)cFHeader.FileNameLength[0];

                    if (fileLength != 0)
                    {
                        Byte[] fileName = new Byte[fileLength];

                        for (int i = 0; i < fileLength; i++)
                        {
                            fileName[i] = buffer[currentIndex++];
                            cFHeader.FullFileName += ((char)fileName[i]).ToString();
                        }
                        cFHeader.FileName = fileName;
                    }

                    //Load extra field if any
                    int extraFieldLength = ((int)cFHeader.ExtraFieldLength[1]) * 256 + (int)cFHeader.ExtraFieldLength[0];

                    if (extraFieldLength != 0)
                    {
                        Byte[] extraField = new Byte[extraFieldLength];

                        for (int i = 0; i < extraFieldLength; i++)
                        {
                            extraField[i] = buffer[currentIndex++];
                        }
                        cFHeader.ExtraField = extraField;
                    }

                    int fileCommentLength = ((int)cFHeader.FileCommentLength[1]) * 256 + (int)cFHeader.FileCommentLength[0];

                    if (fileCommentLength != 0)
                    {
                        Byte[] fileComment = new Byte[fileCommentLength];

                        for (int i = 0; i < fileCommentLength; i++)
                        {
                            fileComment[i] = buffer[currentIndex++];
                        }
                        cFHeader.FileComment = fileComment;
                    }

                    Byte a = buffer[currentIndex];
                    Byte b = buffer[currentIndex + 1];
                    Byte c = buffer[currentIndex + 2];
                    Byte d = buffer[currentIndex + 3];
                    #endregion

                    m_zipEntryNameList.Add(cFHeader);
                }
            }

            //Not found Central Dir. 100% possible. Still valid zip package.
        }
        private void ReadEndOfCentralDirectory(Byte[] buffer)
        {
            int bufferLength = buffer.Length;
            if (bufferLength <= 4)
            {
                throw new ArgumentException("Buffer size is too small. A buffer containing end of central directory must at least greater than 4bytes");
            }

            int index = bufferLength - 1;
            bool found = false;
            int unReadBytesCount = bufferLength;

            while (unReadBytesCount != 0)
            {
                //Reached the boundary and not found central directory
                if (index < 3)
                {
                    break;
                }

                found = (buffer[index - 3] == 0x50) && (buffer[index - 2] == 0X4B) && (buffer[index - 1] == 0x05) && (buffer[index] == 0x06);

                if (found)
                {
                    break;
                }

                index--;
                unReadBytesCount--;
            }

            int currentIndex = index + 1;

            if (found)
            {
                #region Load End Of Central Directory Fields
                m_zipEndCentralDir.DiskNumer = readBytes(buffer, currentIndex, 2);
                currentIndex += 2;

                m_zipEndCentralDir.DiskNumerWithCentralDirectory = readBytes(buffer, currentIndex, 2);
                currentIndex += 2;

                m_zipEndCentralDir.TotalNumerOfEntriesOnThisDisk = readBytes(buffer, currentIndex, 2);
                currentIndex += 2;

                m_zipEndCentralDir.TotalNumerOfEntriesInCentralDirectory = readBytes(buffer, currentIndex, 2);
                currentIndex += 2;

                m_zipEndCentralDir.SizeOfCentralDirectory = readBytes(buffer, currentIndex, 4);
                currentIndex += 4;

                m_zipEndCentralDir.OffSetOfCentralDirectory = readBytes(buffer, currentIndex, 4);
                currentIndex += 4;

                m_zipEndCentralDir.ZipFileCommentLength = readBytes(buffer, currentIndex, 2);
                currentIndex += 2;
                #endregion
            }
        }

        private Byte[] readBytes(Byte[] srcBuffer, int startIndex, int sizeToRead)
        {
            Byte[] bytes;

            switch (sizeToRead)
            {
                case 2:
                    {
                        bytes = new Byte[2];
                        bytes[0] = srcBuffer[startIndex];
                        bytes[1] = srcBuffer[startIndex + 1];
                        break;
                    }
                case 4:
                    {
                        bytes = new Byte[4];
                        bytes[0] = srcBuffer[startIndex];
                        bytes[1] = srcBuffer[startIndex + 1];
                        bytes[2] = srcBuffer[startIndex + 2];
                        bytes[3] = srcBuffer[startIndex + 3];
                        break;
                    }
                case 8:
                    {
                        bytes = new Byte[8];
                        bytes[0] = srcBuffer[startIndex];
                        bytes[1] = srcBuffer[startIndex + 1];
                        bytes[2] = srcBuffer[startIndex + 2];
                        bytes[3] = srcBuffer[startIndex + 3];
                        bytes[4] = srcBuffer[startIndex + 4];
                        bytes[5] = srcBuffer[startIndex + 5];
                        bytes[6] = srcBuffer[startIndex + 6];
                        bytes[7] = srcBuffer[startIndex + 7];
                        break;
                    }
                default:
                    throw new ArgumentException("Invalid buffer size to read : only 2, 4, 8 are supported right now");
            }

            return bytes;
        }
        private Boolean isValidSignature(Byte[] buffer, int startIndex)
        {
            return true;
        }
    }
}
