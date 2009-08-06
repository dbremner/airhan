using System;
using System.Collections.Generic;
using System.Text;

namespace ZIPViewer
{
    class ZipCentralDirFileHeader
    {
        private Byte[] m_signature = new Byte[4];
        private Byte[] m_versionMadeBy = new Byte[2];
        private Byte[] m_versionNeedToExtract = new Byte[2];
        private Byte[] m_bitFlag = new Byte[2];
        private Byte[] m_compressionMethod = new Byte[2];
        private Byte[] m_lastModifyTime = new Byte[2];
        private Byte[] m_lastModifyDate = new Byte[2];
        private Byte[] m_crc32 = new Byte[4];
        private Byte[] m_compressedSize = new Byte[4];
        private Byte[] m_uncompressedSize = new Byte[4];
        private Byte[] m_fileNameLength = new Byte[2];
        private Byte[] m_extraFieldLength = new Byte[2];
        private Byte[] m_fileCommentLength = new Byte[2];
        private Byte[] m_diskNumberStart = new Byte[2];
        private Byte[] m_internalFileAttributes = new Byte[2];
        private Byte[] m_externalFileAttributes = new Byte[4];
        private Byte[] m_relativeOffsetOfLocalFileHeader = new Byte[4];
        private String m_fullFileName;

        private Byte[] m_fileName;
        private Byte[] m_extraField;
        private Byte[] m_fileComment;

        public Byte[] Signature
        {
            get
            {
                return m_signature;
            }
            set
            {
                m_signature = value;
            }
        }
        public Byte[] VersionMadeBy
        {
            get
            {
                return m_versionMadeBy;
            }
            set
            {
                m_versionMadeBy = value;
            }
        }
        public Byte[] VersionNeedToExtract
        {
            get
            {
                return m_versionNeedToExtract;
            }
            set
            {
                m_versionNeedToExtract = value;
            }
        }
        public Byte[] BitFlag
        {
            get
            {
                return m_bitFlag;
            }
            set
            {
                m_bitFlag = value;
            }
        }
        public Byte[] CompressionMethod
        {
            get
            {
                return m_compressionMethod;
            }
            set
            {
                m_compressionMethod = value;
            }
        }
        public Byte[] LastModifyTime
        {
            get
            {
                return m_lastModifyTime;
            }
            set
            {
                m_lastModifyTime = value;
            }
        }
        public Byte[] LastModifyDate
        {
            get
            {
                return m_lastModifyDate;
            }
            set
            {
                m_lastModifyDate = value;
            }
        }
        public Byte[] CRC32
        {
            get
            {
                return m_crc32;
            }
            set
            {
                m_crc32 = value;
            }
        }
        public Byte[] CompressedSize
        {
            get
            {
                return m_compressedSize;
            }
            set
            {
                m_compressedSize = value;
            }
        }
        public Byte[] UncompressedSize
        {
            get
            {
                return m_uncompressedSize;
            }
            set
            {
                m_uncompressedSize = value;
            }
        }
        public Byte[] FileNameLength
        {
            get
            {
                return m_fileNameLength;
            }
            set
            {
                m_fileNameLength = value;
            }
        }
        public Byte[] ExtraFieldLength
        {
            get
            {
                return m_extraFieldLength;
            }
            set
            {
                m_extraFieldLength = value;
            }
        }
        public Byte[] FileCommentLength
        {
            get
            {
                return m_fileCommentLength;
            }
            set
            {
                m_fileCommentLength = value;
            }
        }
        public Byte[] DiskNumberStart
        {
            get
            {
                return m_diskNumberStart;
            }
            set
            {
                m_diskNumberStart = value;
            }
        }
        public Byte[] InternalFileAttributes
        {
            get
            {
                return m_internalFileAttributes;
            }
            set
            {
                m_internalFileAttributes = value;
            }
        }
        public Byte[] ExternalFileAttributes
        {
            get
            {
                return m_externalFileAttributes;
            }
            set
            {
                m_externalFileAttributes = value;
            }
        }
        public Byte[] OffSetOfLocalFileHeader
        {
            get
            {
                return m_relativeOffsetOfLocalFileHeader;
            }
            set
            {
                m_relativeOffsetOfLocalFileHeader = value;
            }
        }
        public String FullFileName
        {
            get
            {
                return m_fullFileName;
            }
            set
            {
                m_fullFileName = value;
            }
        }

        public Byte[] FileName
        {
            get
            {
                return m_fileName;
            }
            set
            {
                m_fileName = value;
            }
        }
        public Byte[] ExtraField
        {
            get
            {
                return m_extraField;
            }
            set
            {
                m_extraField = value;
            }
        }
        public Byte[] FileComment
        {
            get
            {
                return m_fileComment;
            }
            set
            {
                m_fileComment = value;
            }
        }
    }
}
