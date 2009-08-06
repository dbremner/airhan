using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ZIPViewer
{
    public partial class ZIPViwer : Form
    {
        private List<ZipCentralDirFileHeader> m_zipItemList = null;

        public ZIPViwer()
        {
            InitializeComponent();
        }

        private void buttonOpenFile_Click(object sender, EventArgs e)
        {
            String fileName = "";
            try
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.Filter = "Zip Files (*.zip)|*.zip";
                openFileDialog.ShowReadOnly = true;
                openFileDialog.Multiselect = false;
                openFileDialog.Title = "Open the file which stores your test cases";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    this.textBoxZipPackageLocation.Text = openFileDialog.FileName;
                    fileName = openFileDialog.FileName;
                    if (String.IsNullOrEmpty(fileName))
                    {
                        throw new ApplicationException("Zip Package name is empty!");
                    }

                    ZipArchive zip = new ZipArchive(fileName);
                    zip.LoadZipMetaData();
                    m_zipItemList = zip.ZipItemList;

           //       MessageBox.Show("There are total " + m_zipItemList.Count.ToString() + " zip items in the package");
                    
                    if (m_zipItemList.Count == 0)
                    {
                        //Empty zip archive, just return
                        return;
                    }

                    int oldItemCount = this.listBoxCDIRFileNameList.Items.Count;
                    if (oldItemCount > 0)
                    {
                        for (int i = 0; i < oldItemCount; i++)
                        {
                            //Keep removing first element to clear the entire list.
                            this.listBoxCDIRFileNameList.Items.RemoveAt(0);
                        }
                    }

                    //Populate zip item list
                    for (int i = 0; i < m_zipItemList.Count; i++)
                    {
                     
                        this.listBoxCDIRFileNameList.Items.Add(m_zipItemList[i].FullFileName);
                    }
    
                    //Load the first zip item as default.
                    ZipCentralDirFileHeader header = m_zipItemList[0];
                    loadCentralDirHeaderFields(header);

                    this.listBoxCDIRFileNameList.SelectedItem = listBoxCDIRFileNameList.Items[0];

                    //Load end of central directory information
                    ZipEndCentralDir zipEnd = zip.ZipEndOfCentralDirectoryRecord;
                    loadEndOfCentralDirectoryFields(zipEnd);
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show("Exception : " + exc.Message, "Error Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void loadCentralDirHeaderFields(ZipCentralDirFileHeader header)
        {
            this.textBoxCDIRBit.Text = formatByteArrayToString(header.BitFlag);
            this.textBoxCDIRCompressedSize.Text = formatByteArrayToString(header.CompressedSize);
            this.textBoxCDIRCompressionMethod.Text = formatByteArrayToString(header.CompressionMethod);
            this.textBoxCDIRCRC32.Text = formatByteArrayToString(header.CRC32);
            this.textBoxCDIRDiskNumberStart.Text = formatByteArrayToString(header.DiskNumberStart);
            this.textBoxCDIRExternalFileAttributes.Text = formatByteArrayToString(header.ExternalFileAttributes);
            this.textBoxCDIRExtraFieldLength.Text = formatByteArrayToString(header.ExtraFieldLength);
            this.textBoxCDIRFileCommentLength.Text = formatByteArrayToString(header.FileCommentLength);
            this.textBoxCDIRFileNameLength.Text = formatByteArrayToString(header.FileNameLength);
            this.textBoxCDIRInternalFileAttributes.Text = formatByteArrayToString(header.InternalFileAttributes);
            this.textBoxCDIRLastModifyDate.Text = formatByteArrayToString(header.LastModifyDate);
            this.textBoxCDIRLastModifyTime.Text = formatByteArrayToString(header.LastModifyTime);
            this.textBoxCDIRLocalFileHeaderOffset.Text = formatByteArrayToString(header.OffSetOfLocalFileHeader);
            this.textBoxCDIRUncompressedSize.Text = formatByteArrayToString(header.UncompressedSize);
            this.textBoxCDIRVersionMadeBy.Text = formatByteArrayToString(header.VersionMadeBy);
            this.textBoxCDIRVersionNeedToExtract.Text = formatByteArrayToString(header.VersionNeedToExtract);
            this.textBoxCDIRFileComment.Text = formatByteArrayToString(header.FileComment);
            this.textBoxCDIRExtraFieldValue.Text = formatByteArrayToString(header.ExtraField);
        }
        private void loadEndOfCentralDirectoryFields(ZipEndCentralDir header)
        {
            this.textBoxEDIRdiskNumber.Text = formatByteArrayToString(header.DiskNumer);
            this.textBoxEDIRdiskNumberWithCentralDir.Text = formatByteArrayToString(header.DiskNumerWithCentralDirectory);
            this.textBoxEDIRoffset.Text = formatByteArrayToString(header.OffSetOfCentralDirectory);
            this.textBoxEDIRsizeOfCentralDirectory.Text = formatByteArrayToString(header.SizeOfCentralDirectory);
            this.textBoxEDIRtotalEntryCentralDir.Text = formatByteArrayToString(header.TotalNumerOfEntriesInCentralDirectory);
            this.textBoxEDIRtotalEntryDisk.Text = formatByteArrayToString(header.TotalNumerOfEntriesOnThisDisk);
            this.textBoxEDIRcommentLength.Text = formatByteArrayToString(header.ZipFileCommentLength);
        }

        private String formatByteArrayToString(Byte[] bytes)
        {
            String returnStr = null;
            if (bytes == null)
            {
                return returnStr;
            }
            for (int i = bytes.Length -1; i >=0; i--)
            {
                if (bytes[i] < 16)
                {
                    returnStr += "0" + String.Format("{0:X}", bytes[i]); ;
                }
                else
                {
                    returnStr += String.Format("{0:X}", bytes[i]);
                }
                
            }
            return returnStr;
        }

        private void listBoxCDIRFileNameList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxCDIRFileNameList.SelectedItem == null)
            {
                return;
            }
            String zipItemName = this.listBoxCDIRFileNameList.SelectedItem.ToString();
            for (int i = 0; i < m_zipItemList.Count; i++)
            {
                if (String.Equals(zipItemName, m_zipItemList[i].FullFileName))
                {
                    loadCentralDirHeaderFields(m_zipItemList[i]);
                    break;
                }
            }
        }
    }
}