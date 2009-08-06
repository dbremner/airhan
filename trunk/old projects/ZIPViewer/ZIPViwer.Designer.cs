namespace ZIPViewer
{
    partial class ZIPViwer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPageEndOfCentralDir = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBoxEDIRcommentLength = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxEDIRoffset = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBoxEDIRsizeOfCentralDirectory = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.textBoxEDIRtotalEntryCentralDir = new System.Windows.Forms.TextBox();
            this.textBoxEDIRtotalEntryDisk = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxEDIRdiskNumberWithCentralDir = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxEDIRdiskNumber = new System.Windows.Forms.TextBox();
            this.tabPageCentralDir = new System.Windows.Forms.TabPage();
            this.groupBoxOpenFile = new System.Windows.Forms.GroupBox();
            this.buttonOpenFile = new System.Windows.Forms.Button();
            this.textBoxZipPackageLocation = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBoxCDIRFileComment = new System.Windows.Forms.TextBox();
            this.textBoxCDIRExtraFieldValue = new System.Windows.Forms.TextBox();
            this.textBoxCDIRLocalFileHeaderOffset = new System.Windows.Forms.TextBox();
            this.textBoxCDIRExternalFileAttributes = new System.Windows.Forms.TextBox();
            this.textBoxCDIRInternalFileAttributes = new System.Windows.Forms.TextBox();
            this.textBoxCDIRDiskNumberStart = new System.Windows.Forms.TextBox();
            this.textBoxCDIRFileCommentLength = new System.Windows.Forms.TextBox();
            this.textBoxCDIRExtraFieldLength = new System.Windows.Forms.TextBox();
            this.textBoxCDIRFileNameLength = new System.Windows.Forms.TextBox();
            this.textBoxCDIRUncompressedSize = new System.Windows.Forms.TextBox();
            this.textBoxCDIRCompressedSize = new System.Windows.Forms.TextBox();
            this.textBoxCDIRCRC32 = new System.Windows.Forms.TextBox();
            this.textBoxCDIRLastModifyDate = new System.Windows.Forms.TextBox();
            this.textBoxCDIRLastModifyTime = new System.Windows.Forms.TextBox();
            this.textBoxCDIRCompressionMethod = new System.Windows.Forms.TextBox();
            this.textBoxCDIRBit = new System.Windows.Forms.TextBox();
            this.labelCDIRFileComment = new System.Windows.Forms.Label();
            this.labelCDIRExtraFieldValue = new System.Windows.Forms.Label();
            this.labelCDIRLocalFileHeaderOffset = new System.Windows.Forms.Label();
            this.labelCDIRExternalFileAttributes = new System.Windows.Forms.Label();
            this.labelCDIRInternalFileAttributes = new System.Windows.Forms.Label();
            this.labelCDIRDiskNumberStart = new System.Windows.Forms.Label();
            this.labelCDIRFileCommentLength = new System.Windows.Forms.Label();
            this.labelCDIRExtraFieldLength = new System.Windows.Forms.Label();
            this.labelCDIRFileNameLength = new System.Windows.Forms.Label();
            this.labelCDIRUncompressedSize = new System.Windows.Forms.Label();
            this.labelCDIRCompressedSize = new System.Windows.Forms.Label();
            this.labelCDIRCRC32 = new System.Windows.Forms.Label();
            this.labelCDIRLastFileModifyDate = new System.Windows.Forms.Label();
            this.labelCDIRFileModifyTime = new System.Windows.Forms.Label();
            this.labelCDIRCMPMethod = new System.Windows.Forms.Label();
            this.labelCDIRBitFlag = new System.Windows.Forms.Label();
            this.textBoxCDIRVersionNeedToExtract = new System.Windows.Forms.TextBox();
            this.labelCDIRVersionNeedToExtract = new System.Windows.Forms.Label();
            this.labelCDIRVersionMadeBy = new System.Windows.Forms.Label();
            this.textBoxCDIRVersionMadeBy = new System.Windows.Forms.TextBox();
            this.groupBoxZipItemList = new System.Windows.Forms.GroupBox();
            this.listBoxCDIRFileNameList = new System.Windows.Forms.ListBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPageEndOfCentralDir.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.tabPageCentralDir.SuspendLayout();
            this.groupBoxOpenFile.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBoxZipItemList.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabPage1
            // 
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(746, 612);
            this.tabPage1.TabIndex = 2;
            this.tabPage1.Text = "ZIP 64 End Of Central Directory";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPageEndOfCentralDir
            // 
            this.tabPageEndOfCentralDir.Controls.Add(this.groupBox2);
            this.tabPageEndOfCentralDir.Location = new System.Drawing.Point(4, 22);
            this.tabPageEndOfCentralDir.Name = "tabPageEndOfCentralDir";
            this.tabPageEndOfCentralDir.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageEndOfCentralDir.Size = new System.Drawing.Size(746, 612);
            this.tabPageEndOfCentralDir.TabIndex = 1;
            this.tabPageEndOfCentralDir.Text = "End Of Central Directory";
            this.tabPageEndOfCentralDir.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBoxEDIRcommentLength);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.textBoxEDIRoffset);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.textBoxEDIRsizeOfCentralDirectory);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.textBoxEDIRtotalEntryCentralDir);
            this.groupBox2.Controls.Add(this.textBoxEDIRtotalEntryDisk);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.textBoxEDIRdiskNumberWithCentralDir);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.textBoxEDIRdiskNumber);
            this.groupBox2.Location = new System.Drawing.Point(6, 6);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(434, 600);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "End Of Central Directory Records";
            // 
            // textBoxEDIRcommentLength
            // 
            this.textBoxEDIRcommentLength.Location = new System.Drawing.Point(248, 180);
            this.textBoxEDIRcommentLength.Name = "textBoxEDIRcommentLength";
            this.textBoxEDIRcommentLength.ReadOnly = true;
            this.textBoxEDIRcommentLength.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRcommentLength.TabIndex = 20;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 184);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(124, 13);
            this.label3.TabIndex = 19;
            this.label3.Text = "Zip File Comment Length";
            // 
            // textBoxEDIRoffset
            // 
            this.textBoxEDIRoffset.Location = new System.Drawing.Point(248, 154);
            this.textBoxEDIRoffset.Name = "textBoxEDIRoffset";
            this.textBoxEDIRoffset.ReadOnly = true;
            this.textBoxEDIRoffset.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRoffset.TabIndex = 18;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(6, 161);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(130, 13);
            this.label10.TabIndex = 17;
            this.label10.Text = "Offset Of Central Directory";
            // 
            // textBoxEDIRsizeOfCentralDirectory
            // 
            this.textBoxEDIRsizeOfCentralDirectory.Location = new System.Drawing.Point(248, 130);
            this.textBoxEDIRsizeOfCentralDirectory.Name = "textBoxEDIRsizeOfCentralDirectory";
            this.textBoxEDIRsizeOfCentralDirectory.ReadOnly = true;
            this.textBoxEDIRsizeOfCentralDirectory.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRsizeOfCentralDirectory.TabIndex = 16;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 137);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(122, 13);
            this.label9.TabIndex = 15;
            this.label9.Text = "Size Of Central Directory";
            // 
            // textBoxEDIRtotalEntryCentralDir
            // 
            this.textBoxEDIRtotalEntryCentralDir.Location = new System.Drawing.Point(248, 104);
            this.textBoxEDIRtotalEntryCentralDir.Name = "textBoxEDIRtotalEntryCentralDir";
            this.textBoxEDIRtotalEntryCentralDir.ReadOnly = true;
            this.textBoxEDIRtotalEntryCentralDir.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRtotalEntryCentralDir.TabIndex = 14;
            // 
            // textBoxEDIRtotalEntryDisk
            // 
            this.textBoxEDIRtotalEntryDisk.Location = new System.Drawing.Point(248, 78);
            this.textBoxEDIRtotalEntryDisk.Name = "textBoxEDIRtotalEntryDisk";
            this.textBoxEDIRtotalEntryDisk.ReadOnly = true;
            this.textBoxEDIRtotalEntryDisk.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRtotalEntryDisk.TabIndex = 13;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(6, 85);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(178, 13);
            this.label8.TabIndex = 12;
            this.label8.Text = "Total Number Of Entries On this disk";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 112);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(213, 13);
            this.label7.TabIndex = 11;
            this.label7.Text = "Total Number Of Entries In Central Directory";
            // 
            // textBoxEDIRdiskNumberWithCentralDir
            // 
            this.textBoxEDIRdiskNumberWithCentralDir.Location = new System.Drawing.Point(248, 52);
            this.textBoxEDIRdiskNumberWithCentralDir.Name = "textBoxEDIRdiskNumberWithCentralDir";
            this.textBoxEDIRdiskNumberWithCentralDir.ReadOnly = true;
            this.textBoxEDIRdiskNumberWithCentralDir.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRdiskNumberWithCentralDir.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 59);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(236, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Number Of this Disk with start of central directory";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(105, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Number Of This Disk";
            // 
            // textBoxEDIRdiskNumber
            // 
            this.textBoxEDIRdiskNumber.Location = new System.Drawing.Point(248, 26);
            this.textBoxEDIRdiskNumber.Name = "textBoxEDIRdiskNumber";
            this.textBoxEDIRdiskNumber.ReadOnly = true;
            this.textBoxEDIRdiskNumber.Size = new System.Drawing.Size(175, 20);
            this.textBoxEDIRdiskNumber.TabIndex = 4;
            // 
            // tabPageCentralDir
            // 
            this.tabPageCentralDir.Controls.Add(this.groupBoxOpenFile);
            this.tabPageCentralDir.Controls.Add(this.groupBox1);
            this.tabPageCentralDir.Controls.Add(this.groupBoxZipItemList);
            this.tabPageCentralDir.Location = new System.Drawing.Point(4, 22);
            this.tabPageCentralDir.Name = "tabPageCentralDir";
            this.tabPageCentralDir.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageCentralDir.Size = new System.Drawing.Size(746, 612);
            this.tabPageCentralDir.TabIndex = 0;
            this.tabPageCentralDir.Text = "Central Directory File Headers";
            this.tabPageCentralDir.UseVisualStyleBackColor = true;
            // 
            // groupBoxOpenFile
            // 
            this.groupBoxOpenFile.Controls.Add(this.buttonOpenFile);
            this.groupBoxOpenFile.Controls.Add(this.textBoxZipPackageLocation);
            this.groupBoxOpenFile.Location = new System.Drawing.Point(16, 554);
            this.groupBoxOpenFile.Name = "groupBoxOpenFile";
            this.groupBoxOpenFile.Size = new System.Drawing.Size(724, 52);
            this.groupBoxOpenFile.TabIndex = 4;
            this.groupBoxOpenFile.TabStop = false;
            this.groupBoxOpenFile.Text = "Open A Zip Package";
            // 
            // buttonOpenFile
            // 
            this.buttonOpenFile.Location = new System.Drawing.Point(6, 19);
            this.buttonOpenFile.Name = "buttonOpenFile";
            this.buttonOpenFile.Size = new System.Drawing.Size(109, 23);
            this.buttonOpenFile.TabIndex = 2;
            this.buttonOpenFile.Text = "Browse";
            this.buttonOpenFile.UseVisualStyleBackColor = true;
            this.buttonOpenFile.Click += new System.EventHandler(this.buttonOpenFile_Click);
            // 
            // textBoxZipPackageLocation
            // 
            this.textBoxZipPackageLocation.Location = new System.Drawing.Point(121, 22);
            this.textBoxZipPackageLocation.Name = "textBoxZipPackageLocation";
            this.textBoxZipPackageLocation.Size = new System.Drawing.Size(582, 20);
            this.textBoxZipPackageLocation.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBoxCDIRFileComment);
            this.groupBox1.Controls.Add(this.textBoxCDIRExtraFieldValue);
            this.groupBox1.Controls.Add(this.textBoxCDIRLocalFileHeaderOffset);
            this.groupBox1.Controls.Add(this.textBoxCDIRExternalFileAttributes);
            this.groupBox1.Controls.Add(this.textBoxCDIRInternalFileAttributes);
            this.groupBox1.Controls.Add(this.textBoxCDIRDiskNumberStart);
            this.groupBox1.Controls.Add(this.textBoxCDIRFileCommentLength);
            this.groupBox1.Controls.Add(this.textBoxCDIRExtraFieldLength);
            this.groupBox1.Controls.Add(this.textBoxCDIRFileNameLength);
            this.groupBox1.Controls.Add(this.textBoxCDIRUncompressedSize);
            this.groupBox1.Controls.Add(this.textBoxCDIRCompressedSize);
            this.groupBox1.Controls.Add(this.textBoxCDIRCRC32);
            this.groupBox1.Controls.Add(this.textBoxCDIRLastModifyDate);
            this.groupBox1.Controls.Add(this.textBoxCDIRLastModifyTime);
            this.groupBox1.Controls.Add(this.textBoxCDIRCompressionMethod);
            this.groupBox1.Controls.Add(this.textBoxCDIRBit);
            this.groupBox1.Controls.Add(this.labelCDIRFileComment);
            this.groupBox1.Controls.Add(this.labelCDIRExtraFieldValue);
            this.groupBox1.Controls.Add(this.labelCDIRLocalFileHeaderOffset);
            this.groupBox1.Controls.Add(this.labelCDIRExternalFileAttributes);
            this.groupBox1.Controls.Add(this.labelCDIRInternalFileAttributes);
            this.groupBox1.Controls.Add(this.labelCDIRDiskNumberStart);
            this.groupBox1.Controls.Add(this.labelCDIRFileCommentLength);
            this.groupBox1.Controls.Add(this.labelCDIRExtraFieldLength);
            this.groupBox1.Controls.Add(this.labelCDIRFileNameLength);
            this.groupBox1.Controls.Add(this.labelCDIRUncompressedSize);
            this.groupBox1.Controls.Add(this.labelCDIRCompressedSize);
            this.groupBox1.Controls.Add(this.labelCDIRCRC32);
            this.groupBox1.Controls.Add(this.labelCDIRLastFileModifyDate);
            this.groupBox1.Controls.Add(this.labelCDIRFileModifyTime);
            this.groupBox1.Controls.Add(this.labelCDIRCMPMethod);
            this.groupBox1.Controls.Add(this.labelCDIRBitFlag);
            this.groupBox1.Controls.Add(this.textBoxCDIRVersionNeedToExtract);
            this.groupBox1.Controls.Add(this.labelCDIRVersionNeedToExtract);
            this.groupBox1.Controls.Add(this.labelCDIRVersionMadeBy);
            this.groupBox1.Controls.Add(this.textBoxCDIRVersionMadeBy);
            this.groupBox1.Location = new System.Drawing.Point(377, 18);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(363, 530);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Header Values (HEX)";
            // 
            // textBoxCDIRFileComment
            // 
            this.textBoxCDIRFileComment.Location = new System.Drawing.Point(147, 455);
            this.textBoxCDIRFileComment.Name = "textBoxCDIRFileComment";
            this.textBoxCDIRFileComment.ReadOnly = true;
            this.textBoxCDIRFileComment.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRFileComment.TabIndex = 36;
            // 
            // textBoxCDIRExtraFieldValue
            // 
            this.textBoxCDIRExtraFieldValue.Location = new System.Drawing.Point(147, 429);
            this.textBoxCDIRExtraFieldValue.Name = "textBoxCDIRExtraFieldValue";
            this.textBoxCDIRExtraFieldValue.ReadOnly = true;
            this.textBoxCDIRExtraFieldValue.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRExtraFieldValue.TabIndex = 35;
            // 
            // textBoxCDIRLocalFileHeaderOffset
            // 
            this.textBoxCDIRLocalFileHeaderOffset.Location = new System.Drawing.Point(147, 403);
            this.textBoxCDIRLocalFileHeaderOffset.Name = "textBoxCDIRLocalFileHeaderOffset";
            this.textBoxCDIRLocalFileHeaderOffset.ReadOnly = true;
            this.textBoxCDIRLocalFileHeaderOffset.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRLocalFileHeaderOffset.TabIndex = 34;
            // 
            // textBoxCDIRExternalFileAttributes
            // 
            this.textBoxCDIRExternalFileAttributes.Location = new System.Drawing.Point(147, 377);
            this.textBoxCDIRExternalFileAttributes.Name = "textBoxCDIRExternalFileAttributes";
            this.textBoxCDIRExternalFileAttributes.ReadOnly = true;
            this.textBoxCDIRExternalFileAttributes.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRExternalFileAttributes.TabIndex = 33;
            // 
            // textBoxCDIRInternalFileAttributes
            // 
            this.textBoxCDIRInternalFileAttributes.Location = new System.Drawing.Point(147, 351);
            this.textBoxCDIRInternalFileAttributes.Name = "textBoxCDIRInternalFileAttributes";
            this.textBoxCDIRInternalFileAttributes.ReadOnly = true;
            this.textBoxCDIRInternalFileAttributes.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRInternalFileAttributes.TabIndex = 32;
            // 
            // textBoxCDIRDiskNumberStart
            // 
            this.textBoxCDIRDiskNumberStart.Location = new System.Drawing.Point(147, 325);
            this.textBoxCDIRDiskNumberStart.Name = "textBoxCDIRDiskNumberStart";
            this.textBoxCDIRDiskNumberStart.ReadOnly = true;
            this.textBoxCDIRDiskNumberStart.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRDiskNumberStart.TabIndex = 31;
            // 
            // textBoxCDIRFileCommentLength
            // 
            this.textBoxCDIRFileCommentLength.Location = new System.Drawing.Point(147, 299);
            this.textBoxCDIRFileCommentLength.Name = "textBoxCDIRFileCommentLength";
            this.textBoxCDIRFileCommentLength.ReadOnly = true;
            this.textBoxCDIRFileCommentLength.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRFileCommentLength.TabIndex = 30;
            // 
            // textBoxCDIRExtraFieldLength
            // 
            this.textBoxCDIRExtraFieldLength.Location = new System.Drawing.Point(147, 273);
            this.textBoxCDIRExtraFieldLength.Name = "textBoxCDIRExtraFieldLength";
            this.textBoxCDIRExtraFieldLength.ReadOnly = true;
            this.textBoxCDIRExtraFieldLength.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRExtraFieldLength.TabIndex = 29;
            // 
            // textBoxCDIRFileNameLength
            // 
            this.textBoxCDIRFileNameLength.Location = new System.Drawing.Point(147, 247);
            this.textBoxCDIRFileNameLength.Name = "textBoxCDIRFileNameLength";
            this.textBoxCDIRFileNameLength.ReadOnly = true;
            this.textBoxCDIRFileNameLength.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRFileNameLength.TabIndex = 28;
            // 
            // textBoxCDIRUncompressedSize
            // 
            this.textBoxCDIRUncompressedSize.Location = new System.Drawing.Point(147, 221);
            this.textBoxCDIRUncompressedSize.Name = "textBoxCDIRUncompressedSize";
            this.textBoxCDIRUncompressedSize.ReadOnly = true;
            this.textBoxCDIRUncompressedSize.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRUncompressedSize.TabIndex = 27;
            // 
            // textBoxCDIRCompressedSize
            // 
            this.textBoxCDIRCompressedSize.Location = new System.Drawing.Point(147, 195);
            this.textBoxCDIRCompressedSize.Name = "textBoxCDIRCompressedSize";
            this.textBoxCDIRCompressedSize.ReadOnly = true;
            this.textBoxCDIRCompressedSize.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRCompressedSize.TabIndex = 26;
            // 
            // textBoxCDIRCRC32
            // 
            this.textBoxCDIRCRC32.Location = new System.Drawing.Point(147, 168);
            this.textBoxCDIRCRC32.Name = "textBoxCDIRCRC32";
            this.textBoxCDIRCRC32.ReadOnly = true;
            this.textBoxCDIRCRC32.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRCRC32.TabIndex = 25;
            // 
            // textBoxCDIRLastModifyDate
            // 
            this.textBoxCDIRLastModifyDate.Location = new System.Drawing.Point(147, 142);
            this.textBoxCDIRLastModifyDate.Name = "textBoxCDIRLastModifyDate";
            this.textBoxCDIRLastModifyDate.ReadOnly = true;
            this.textBoxCDIRLastModifyDate.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRLastModifyDate.TabIndex = 24;
            // 
            // textBoxCDIRLastModifyTime
            // 
            this.textBoxCDIRLastModifyTime.Location = new System.Drawing.Point(147, 116);
            this.textBoxCDIRLastModifyTime.Name = "textBoxCDIRLastModifyTime";
            this.textBoxCDIRLastModifyTime.ReadOnly = true;
            this.textBoxCDIRLastModifyTime.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRLastModifyTime.TabIndex = 23;
            // 
            // textBoxCDIRCompressionMethod
            // 
            this.textBoxCDIRCompressionMethod.Location = new System.Drawing.Point(147, 90);
            this.textBoxCDIRCompressionMethod.Name = "textBoxCDIRCompressionMethod";
            this.textBoxCDIRCompressionMethod.ReadOnly = true;
            this.textBoxCDIRCompressionMethod.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRCompressionMethod.TabIndex = 22;
            // 
            // textBoxCDIRBit
            // 
            this.textBoxCDIRBit.Location = new System.Drawing.Point(147, 64);
            this.textBoxCDIRBit.Name = "textBoxCDIRBit";
            this.textBoxCDIRBit.ReadOnly = true;
            this.textBoxCDIRBit.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRBit.TabIndex = 21;
            // 
            // labelCDIRFileComment
            // 
            this.labelCDIRFileComment.AutoSize = true;
            this.labelCDIRFileComment.Location = new System.Drawing.Point(7, 462);
            this.labelCDIRFileComment.Name = "labelCDIRFileComment";
            this.labelCDIRFileComment.Size = new System.Drawing.Size(70, 13);
            this.labelCDIRFileComment.TabIndex = 20;
            this.labelCDIRFileComment.Text = "File Comment";
            // 
            // labelCDIRExtraFieldValue
            // 
            this.labelCDIRExtraFieldValue.AutoSize = true;
            this.labelCDIRExtraFieldValue.Location = new System.Drawing.Point(6, 436);
            this.labelCDIRExtraFieldValue.Name = "labelCDIRExtraFieldValue";
            this.labelCDIRExtraFieldValue.Size = new System.Drawing.Size(86, 13);
            this.labelCDIRExtraFieldValue.TabIndex = 19;
            this.labelCDIRExtraFieldValue.Text = "Extra Field Value";
            // 
            // labelCDIRLocalFileHeaderOffset
            // 
            this.labelCDIRLocalFileHeaderOffset.AutoSize = true;
            this.labelCDIRLocalFileHeaderOffset.Location = new System.Drawing.Point(5, 411);
            this.labelCDIRLocalFileHeaderOffset.Name = "labelCDIRLocalFileHeaderOffset";
            this.labelCDIRLocalFileHeaderOffset.Size = new System.Drawing.Size(121, 13);
            this.labelCDIRLocalFileHeaderOffset.TabIndex = 18;
            this.labelCDIRLocalFileHeaderOffset.Text = "Local File Header Offset";
            // 
            // labelCDIRExternalFileAttributes
            // 
            this.labelCDIRExternalFileAttributes.AutoSize = true;
            this.labelCDIRExternalFileAttributes.Location = new System.Drawing.Point(5, 384);
            this.labelCDIRExternalFileAttributes.Name = "labelCDIRExternalFileAttributes";
            this.labelCDIRExternalFileAttributes.Size = new System.Drawing.Size(111, 13);
            this.labelCDIRExternalFileAttributes.TabIndex = 17;
            this.labelCDIRExternalFileAttributes.Text = "External File Attributes";
            // 
            // labelCDIRInternalFileAttributes
            // 
            this.labelCDIRInternalFileAttributes.AutoSize = true;
            this.labelCDIRInternalFileAttributes.Location = new System.Drawing.Point(5, 358);
            this.labelCDIRInternalFileAttributes.Name = "labelCDIRInternalFileAttributes";
            this.labelCDIRInternalFileAttributes.Size = new System.Drawing.Size(108, 13);
            this.labelCDIRInternalFileAttributes.TabIndex = 16;
            this.labelCDIRInternalFileAttributes.Text = "Internal File Attributes";
            // 
            // labelCDIRDiskNumberStart
            // 
            this.labelCDIRDiskNumberStart.AutoSize = true;
            this.labelCDIRDiskNumberStart.Location = new System.Drawing.Point(7, 332);
            this.labelCDIRDiskNumberStart.Name = "labelCDIRDiskNumberStart";
            this.labelCDIRDiskNumberStart.Size = new System.Drawing.Size(93, 13);
            this.labelCDIRDiskNumberStart.TabIndex = 15;
            this.labelCDIRDiskNumberStart.Text = "Disk Number Start";
            // 
            // labelCDIRFileCommentLength
            // 
            this.labelCDIRFileCommentLength.AutoSize = true;
            this.labelCDIRFileCommentLength.Location = new System.Drawing.Point(7, 306);
            this.labelCDIRFileCommentLength.Name = "labelCDIRFileCommentLength";
            this.labelCDIRFileCommentLength.Size = new System.Drawing.Size(106, 13);
            this.labelCDIRFileCommentLength.TabIndex = 14;
            this.labelCDIRFileCommentLength.Text = "File Comment Length";
            // 
            // labelCDIRExtraFieldLength
            // 
            this.labelCDIRExtraFieldLength.AutoSize = true;
            this.labelCDIRExtraFieldLength.Location = new System.Drawing.Point(6, 280);
            this.labelCDIRExtraFieldLength.Name = "labelCDIRExtraFieldLength";
            this.labelCDIRExtraFieldLength.Size = new System.Drawing.Size(92, 13);
            this.labelCDIRExtraFieldLength.TabIndex = 13;
            this.labelCDIRExtraFieldLength.Text = "Extra Field Length";
            // 
            // labelCDIRFileNameLength
            // 
            this.labelCDIRFileNameLength.AutoSize = true;
            this.labelCDIRFileNameLength.Location = new System.Drawing.Point(5, 250);
            this.labelCDIRFileNameLength.Name = "labelCDIRFileNameLength";
            this.labelCDIRFileNameLength.Size = new System.Drawing.Size(90, 13);
            this.labelCDIRFileNameLength.TabIndex = 12;
            this.labelCDIRFileNameLength.Text = "File Name Length";
            // 
            // labelCDIRUncompressedSize
            // 
            this.labelCDIRUncompressedSize.AutoSize = true;
            this.labelCDIRUncompressedSize.Location = new System.Drawing.Point(5, 228);
            this.labelCDIRUncompressedSize.Name = "labelCDIRUncompressedSize";
            this.labelCDIRUncompressedSize.Size = new System.Drawing.Size(101, 13);
            this.labelCDIRUncompressedSize.TabIndex = 11;
            this.labelCDIRUncompressedSize.Text = "Uncompressed Size";
            // 
            // labelCDIRCompressedSize
            // 
            this.labelCDIRCompressedSize.AutoSize = true;
            this.labelCDIRCompressedSize.Location = new System.Drawing.Point(6, 202);
            this.labelCDIRCompressedSize.Name = "labelCDIRCompressedSize";
            this.labelCDIRCompressedSize.Size = new System.Drawing.Size(88, 13);
            this.labelCDIRCompressedSize.TabIndex = 10;
            this.labelCDIRCompressedSize.Text = "Compressed Size";
            // 
            // labelCDIRCRC32
            // 
            this.labelCDIRCRC32.AutoSize = true;
            this.labelCDIRCRC32.Location = new System.Drawing.Point(7, 175);
            this.labelCDIRCRC32.Name = "labelCDIRCRC32";
            this.labelCDIRCRC32.Size = new System.Drawing.Size(41, 13);
            this.labelCDIRCRC32.TabIndex = 9;
            this.labelCDIRCRC32.Text = "CRC32";
            // 
            // labelCDIRLastFileModifyDate
            // 
            this.labelCDIRLastFileModifyDate.AutoSize = true;
            this.labelCDIRLastFileModifyDate.Location = new System.Drawing.Point(7, 145);
            this.labelCDIRLastFileModifyDate.Name = "labelCDIRLastFileModifyDate";
            this.labelCDIRLastFileModifyDate.Size = new System.Drawing.Size(106, 13);
            this.labelCDIRLastFileModifyDate.TabIndex = 8;
            this.labelCDIRLastFileModifyDate.Text = "Last File Modify Date";
            // 
            // labelCDIRFileModifyTime
            // 
            this.labelCDIRFileModifyTime.AutoSize = true;
            this.labelCDIRFileModifyTime.Location = new System.Drawing.Point(7, 123);
            this.labelCDIRFileModifyTime.Name = "labelCDIRFileModifyTime";
            this.labelCDIRFileModifyTime.Size = new System.Drawing.Size(106, 13);
            this.labelCDIRFileModifyTime.TabIndex = 7;
            this.labelCDIRFileModifyTime.Text = "Last File Modify Time";
            // 
            // labelCDIRCMPMethod
            // 
            this.labelCDIRCMPMethod.AutoSize = true;
            this.labelCDIRCMPMethod.Location = new System.Drawing.Point(7, 97);
            this.labelCDIRCMPMethod.Name = "labelCDIRCMPMethod";
            this.labelCDIRCMPMethod.Size = new System.Drawing.Size(106, 13);
            this.labelCDIRCMPMethod.TabIndex = 6;
            this.labelCDIRCMPMethod.Text = "Compression Method";
            // 
            // labelCDIRBitFlag
            // 
            this.labelCDIRBitFlag.AutoSize = true;
            this.labelCDIRBitFlag.Location = new System.Drawing.Point(5, 71);
            this.labelCDIRBitFlag.Name = "labelCDIRBitFlag";
            this.labelCDIRBitFlag.Size = new System.Drawing.Size(124, 13);
            this.labelCDIRBitFlag.TabIndex = 5;
            this.labelCDIRBitFlag.Text = "General Purpose Bit Flag";
            // 
            // textBoxCDIRVersionNeedToExtract
            // 
            this.textBoxCDIRVersionNeedToExtract.Location = new System.Drawing.Point(147, 38);
            this.textBoxCDIRVersionNeedToExtract.Name = "textBoxCDIRVersionNeedToExtract";
            this.textBoxCDIRVersionNeedToExtract.ReadOnly = true;
            this.textBoxCDIRVersionNeedToExtract.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRVersionNeedToExtract.TabIndex = 4;
            // 
            // labelCDIRVersionNeedToExtract
            // 
            this.labelCDIRVersionNeedToExtract.AutoSize = true;
            this.labelCDIRVersionNeedToExtract.Location = new System.Drawing.Point(6, 45);
            this.labelCDIRVersionNeedToExtract.Name = "labelCDIRVersionNeedToExtract";
            this.labelCDIRVersionNeedToExtract.Size = new System.Drawing.Size(123, 13);
            this.labelCDIRVersionNeedToExtract.TabIndex = 3;
            this.labelCDIRVersionNeedToExtract.Text = "Version Need To Extract";
            // 
            // labelCDIRVersionMadeBy
            // 
            this.labelCDIRVersionMadeBy.AutoSize = true;
            this.labelCDIRVersionMadeBy.Location = new System.Drawing.Point(6, 19);
            this.labelCDIRVersionMadeBy.Name = "labelCDIRVersionMadeBy";
            this.labelCDIRVersionMadeBy.Size = new System.Drawing.Size(87, 13);
            this.labelCDIRVersionMadeBy.TabIndex = 1;
            this.labelCDIRVersionMadeBy.Text = "Version Made By";
            // 
            // textBoxCDIRVersionMadeBy
            // 
            this.textBoxCDIRVersionMadeBy.Location = new System.Drawing.Point(147, 12);
            this.textBoxCDIRVersionMadeBy.Name = "textBoxCDIRVersionMadeBy";
            this.textBoxCDIRVersionMadeBy.ReadOnly = true;
            this.textBoxCDIRVersionMadeBy.Size = new System.Drawing.Size(175, 20);
            this.textBoxCDIRVersionMadeBy.TabIndex = 2;
            // 
            // groupBoxZipItemList
            // 
            this.groupBoxZipItemList.Controls.Add(this.listBoxCDIRFileNameList);
            this.groupBoxZipItemList.Location = new System.Drawing.Point(16, 18);
            this.groupBoxZipItemList.Name = "groupBoxZipItemList";
            this.groupBoxZipItemList.Size = new System.Drawing.Size(345, 530);
            this.groupBoxZipItemList.TabIndex = 0;
            this.groupBoxZipItemList.TabStop = false;
            this.groupBoxZipItemList.Text = "Zip Item List";
            // 
            // listBoxCDIRFileNameList
            // 
            this.listBoxCDIRFileNameList.FormattingEnabled = true;
            this.listBoxCDIRFileNameList.Location = new System.Drawing.Point(6, 19);
            this.listBoxCDIRFileNameList.Name = "listBoxCDIRFileNameList";
            this.listBoxCDIRFileNameList.Size = new System.Drawing.Size(328, 498);
            this.listBoxCDIRFileNameList.TabIndex = 0;
            this.listBoxCDIRFileNameList.SelectedIndexChanged += new System.EventHandler(this.listBoxCDIRFileNameList_SelectedIndexChanged);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPageCentralDir);
            this.tabControl1.Controls.Add(this.tabPageEndOfCentralDir);
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(754, 638);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(746, 612);
            this.tabPage2.TabIndex = 3;
            this.tabPage2.Text = "Deflate Block View";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // ZIPViwer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(778, 662);
            this.Controls.Add(this.tabControl1);
            this.Name = "ZIPViwer";
            this.Text = "ZIP Viewer";
            this.tabPageEndOfCentralDir.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.tabPageCentralDir.ResumeLayout(false);
            this.groupBoxOpenFile.ResumeLayout(false);
            this.groupBoxOpenFile.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBoxZipItemList.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPageEndOfCentralDir;
        private System.Windows.Forms.TabPage tabPageCentralDir;
        private System.Windows.Forms.GroupBox groupBoxOpenFile;
        private System.Windows.Forms.Button buttonOpenFile;
        private System.Windows.Forms.TextBox textBoxZipPackageLocation;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBoxCDIRFileComment;
        private System.Windows.Forms.TextBox textBoxCDIRExtraFieldValue;
        private System.Windows.Forms.TextBox textBoxCDIRLocalFileHeaderOffset;
        private System.Windows.Forms.TextBox textBoxCDIRExternalFileAttributes;
        private System.Windows.Forms.TextBox textBoxCDIRInternalFileAttributes;
        private System.Windows.Forms.TextBox textBoxCDIRDiskNumberStart;
        private System.Windows.Forms.TextBox textBoxCDIRFileCommentLength;
        private System.Windows.Forms.TextBox textBoxCDIRExtraFieldLength;
        private System.Windows.Forms.TextBox textBoxCDIRFileNameLength;
        private System.Windows.Forms.TextBox textBoxCDIRUncompressedSize;
        private System.Windows.Forms.TextBox textBoxCDIRCompressedSize;
        private System.Windows.Forms.TextBox textBoxCDIRCRC32;
        private System.Windows.Forms.TextBox textBoxCDIRLastModifyDate;
        private System.Windows.Forms.TextBox textBoxCDIRLastModifyTime;
        private System.Windows.Forms.TextBox textBoxCDIRCompressionMethod;
        private System.Windows.Forms.TextBox textBoxCDIRBit;
        private System.Windows.Forms.Label labelCDIRFileComment;
        private System.Windows.Forms.Label labelCDIRExtraFieldValue;
        private System.Windows.Forms.Label labelCDIRLocalFileHeaderOffset;
        private System.Windows.Forms.Label labelCDIRExternalFileAttributes;
        private System.Windows.Forms.Label labelCDIRInternalFileAttributes;
        private System.Windows.Forms.Label labelCDIRDiskNumberStart;
        private System.Windows.Forms.Label labelCDIRFileCommentLength;
        private System.Windows.Forms.Label labelCDIRExtraFieldLength;
        private System.Windows.Forms.Label labelCDIRFileNameLength;
        private System.Windows.Forms.Label labelCDIRUncompressedSize;
        private System.Windows.Forms.Label labelCDIRCompressedSize;
        private System.Windows.Forms.Label labelCDIRCRC32;
        private System.Windows.Forms.Label labelCDIRLastFileModifyDate;
        private System.Windows.Forms.Label labelCDIRFileModifyTime;
        private System.Windows.Forms.Label labelCDIRCMPMethod;
        private System.Windows.Forms.Label labelCDIRBitFlag;
        private System.Windows.Forms.TextBox textBoxCDIRVersionNeedToExtract;
        private System.Windows.Forms.Label labelCDIRVersionNeedToExtract;
        private System.Windows.Forms.Label labelCDIRVersionMadeBy;
        private System.Windows.Forms.TextBox textBoxCDIRVersionMadeBy;
        private System.Windows.Forms.GroupBox groupBoxZipItemList;
        private System.Windows.Forms.ListBox listBoxCDIRFileNameList;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxEDIRdiskNumber;
        private System.Windows.Forms.TextBox textBoxEDIRdiskNumberWithCentralDir;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBoxEDIRtotalEntryDisk;
        private System.Windows.Forms.TextBox textBoxEDIRsizeOfCentralDirectory;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBoxEDIRtotalEntryCentralDir;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxEDIRoffset;
        private System.Windows.Forms.TextBox textBoxEDIRcommentLength;
        private System.Windows.Forms.TabPage tabPage2;

    }
}

