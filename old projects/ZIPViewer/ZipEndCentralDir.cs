using System;
using System.Collections.Generic;
using System.Text;

namespace ZIPViewer
{
    class ZipEndCentralDir
    {
        private Byte[] m_diskNumer;
        private Byte[] m_diskNumerStartWithCentralDirectory;
        private Byte[] m_totalNumberOfEntriesOnThisDisk;
        private Byte[] m_totalNumberOfEntriesInCentralDirectory;
        private Byte[] m_sizeOfCentralDirectory;
        private Byte[] m_offSetOfCentralDirectory;
        private Byte[] m_zipFileCommentLength;
        private Byte[] m_zipFileComment;

        public Byte[] DiskNumer
        {
            get
            {
                return m_diskNumer;
            }
            set
            {
                m_diskNumer = value;
            }
        }
        public Byte[] DiskNumerWithCentralDirectory
        {
            get
            {
                return m_diskNumerStartWithCentralDirectory;
            }
            set
            {
                m_diskNumerStartWithCentralDirectory = value;
            }
        }
        public Byte[] TotalNumerOfEntriesOnThisDisk
        {
            get
            {
                return m_totalNumberOfEntriesOnThisDisk;
            }
            set
            {
                m_totalNumberOfEntriesOnThisDisk = value;
            }
        }
        public Byte[] TotalNumerOfEntriesInCentralDirectory
        {
            get
            {
                return m_totalNumberOfEntriesInCentralDirectory;
            }
            set
            {
                m_totalNumberOfEntriesInCentralDirectory = value;
            }
        }
        public Byte[] SizeOfCentralDirectory
        {
            get
            {
                return m_sizeOfCentralDirectory;
            }
            set
            {
                m_sizeOfCentralDirectory = value;
            }
        }
        public Byte[] OffSetOfCentralDirectory
        {
            get
            {
                return m_offSetOfCentralDirectory;
            }
            set
            {
                m_offSetOfCentralDirectory = value;
            }
        }
        public Byte[] ZipFileCommentLength
        {
            get
            {
                return m_zipFileCommentLength;
            }
            set
            {
                m_zipFileCommentLength = value;
            }
        }
        public Byte[] ZipFileComment
        {
            get
            {
                return m_zipFileComment;
            }
            set
            {
                m_zipFileComment = value;
            }
        }
    }
}
