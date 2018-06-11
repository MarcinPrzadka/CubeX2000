namespace LedCube
{
    partial class CubeX2000
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.ProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this.status_label = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.disconnect_button = new System.Windows.Forms.Button();
            this.connect_button = new System.Windows.Forms.Button();
            this.PortsList = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button_0 = new System.Windows.Forms.Button();
            this.button_3 = new System.Windows.Forms.Button();
            this.button_6 = new System.Windows.Forms.Button();
            this.button_9 = new System.Windows.Forms.Button();
            this.button_2 = new System.Windows.Forms.Button();
            this.button_5 = new System.Windows.Forms.Button();
            this.button_8 = new System.Windows.Forms.Button();
            this.button_1 = new System.Windows.Forms.Button();
            this.button_4 = new System.Windows.Forms.Button();
            this.button_7 = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.sent_text = new System.Windows.Forms.TextBox();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.statusStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ProgressBar,
            this.status_label});
            this.statusStrip1.Location = new System.Drawing.Point(0, 223);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(433, 22);
            this.statusStrip1.TabIndex = 0;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // ProgressBar
            // 
            this.ProgressBar.Name = "ProgressBar";
            this.ProgressBar.Size = new System.Drawing.Size(100, 16);
            // 
            // status_label
            // 
            this.status_label.Name = "status_label";
            this.status_label.Size = new System.Drawing.Size(106, 17);
            this.status_label.Text = "Choose Serial Port!";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.disconnect_button);
            this.groupBox1.Controls.Add(this.connect_button);
            this.groupBox1.Controls.Add(this.PortsList);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(406, 65);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Serial Port Connection";
            // 
            // disconnect_button
            // 
            this.disconnect_button.Enabled = false;
            this.disconnect_button.Location = new System.Drawing.Point(285, 26);
            this.disconnect_button.Name = "disconnect_button";
            this.disconnect_button.Size = new System.Drawing.Size(98, 23);
            this.disconnect_button.TabIndex = 2;
            this.disconnect_button.Text = "Disconnect";
            this.disconnect_button.UseVisualStyleBackColor = true;
            this.disconnect_button.Click += new System.EventHandler(this.disconnect_button_Click);
            // 
            // connect_button
            // 
            this.connect_button.Location = new System.Drawing.Point(181, 26);
            this.connect_button.Name = "connect_button";
            this.connect_button.Size = new System.Drawing.Size(98, 23);
            this.connect_button.TabIndex = 1;
            this.connect_button.Text = "Connect";
            this.connect_button.UseVisualStyleBackColor = true;
            this.connect_button.Click += new System.EventHandler(this.connect_button_Click);
            // 
            // PortsList
            // 
            this.PortsList.FormattingEnabled = true;
            this.PortsList.Location = new System.Drawing.Point(24, 26);
            this.PortsList.Name = "PortsList";
            this.PortsList.Size = new System.Drawing.Size(151, 21);
            this.PortsList.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.button_0);
            this.groupBox2.Controls.Add(this.button_3);
            this.groupBox2.Controls.Add(this.button_6);
            this.groupBox2.Controls.Add(this.button_9);
            this.groupBox2.Controls.Add(this.button_2);
            this.groupBox2.Controls.Add(this.button_5);
            this.groupBox2.Controls.Add(this.button_8);
            this.groupBox2.Controls.Add(this.button_1);
            this.groupBox2.Controls.Add(this.button_4);
            this.groupBox2.Controls.Add(this.button_7);
            this.groupBox2.Enabled = false;
            this.groupBox2.Location = new System.Drawing.Point(12, 83);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(103, 133);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Sending";
            // 
            // button_0
            // 
            this.button_0.Location = new System.Drawing.Point(9, 104);
            this.button_0.Name = "button_0";
            this.button_0.Size = new System.Drawing.Size(84, 23);
            this.button_0.TabIndex = 11;
            this.button_0.Text = "0";
            this.button_0.UseVisualStyleBackColor = true;
            this.button_0.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_3
            // 
            this.button_3.Location = new System.Drawing.Point(69, 75);
            this.button_3.Name = "button_3";
            this.button_3.Size = new System.Drawing.Size(24, 23);
            this.button_3.TabIndex = 10;
            this.button_3.Text = "3";
            this.button_3.UseVisualStyleBackColor = true;
            this.button_3.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_6
            // 
            this.button_6.Location = new System.Drawing.Point(69, 46);
            this.button_6.Name = "button_6";
            this.button_6.Size = new System.Drawing.Size(24, 23);
            this.button_6.TabIndex = 9;
            this.button_6.Text = "6";
            this.button_6.UseVisualStyleBackColor = true;
            this.button_6.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_9
            // 
            this.button_9.Location = new System.Drawing.Point(69, 18);
            this.button_9.Name = "button_9";
            this.button_9.Size = new System.Drawing.Size(24, 23);
            this.button_9.TabIndex = 8;
            this.button_9.Text = "9";
            this.button_9.UseVisualStyleBackColor = true;
            this.button_9.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_2
            // 
            this.button_2.Location = new System.Drawing.Point(39, 75);
            this.button_2.Name = "button_2";
            this.button_2.Size = new System.Drawing.Size(24, 23);
            this.button_2.TabIndex = 7;
            this.button_2.Text = "2";
            this.button_2.UseVisualStyleBackColor = true;
            this.button_2.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_5
            // 
            this.button_5.Location = new System.Drawing.Point(39, 46);
            this.button_5.Name = "button_5";
            this.button_5.Size = new System.Drawing.Size(24, 23);
            this.button_5.TabIndex = 6;
            this.button_5.Text = "5";
            this.button_5.UseVisualStyleBackColor = true;
            this.button_5.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_8
            // 
            this.button_8.Location = new System.Drawing.Point(39, 17);
            this.button_8.Name = "button_8";
            this.button_8.Size = new System.Drawing.Size(24, 23);
            this.button_8.TabIndex = 5;
            this.button_8.Text = "8";
            this.button_8.UseVisualStyleBackColor = true;
            this.button_8.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_1
            // 
            this.button_1.Location = new System.Drawing.Point(9, 75);
            this.button_1.Name = "button_1";
            this.button_1.Size = new System.Drawing.Size(24, 23);
            this.button_1.TabIndex = 4;
            this.button_1.Text = "1";
            this.button_1.UseVisualStyleBackColor = true;
            this.button_1.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_4
            // 
            this.button_4.Location = new System.Drawing.Point(9, 46);
            this.button_4.Name = "button_4";
            this.button_4.Size = new System.Drawing.Size(24, 23);
            this.button_4.TabIndex = 3;
            this.button_4.Text = "4";
            this.button_4.UseVisualStyleBackColor = true;
            this.button_4.Click += new System.EventHandler(this.send_button_Click);
            // 
            // button_7
            // 
            this.button_7.Location = new System.Drawing.Point(9, 17);
            this.button_7.Name = "button_7";
            this.button_7.Size = new System.Drawing.Size(24, 23);
            this.button_7.TabIndex = 2;
            this.button_7.Text = "7";
            this.button_7.UseVisualStyleBackColor = true;
            this.button_7.Click += new System.EventHandler(this.send_button_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.sent_text);
            this.groupBox3.Enabled = false;
            this.groupBox3.Location = new System.Drawing.Point(121, 83);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(297, 133);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Sent History";
            // 
            // sent_text
            // 
            this.sent_text.AccessibleRole = System.Windows.Forms.AccessibleRole.Text;
            this.sent_text.Location = new System.Drawing.Point(24, 17);
            this.sent_text.Multiline = true;
            this.sent_text.Name = "sent_text";
            this.sent_text.ReadOnly = true;
            this.sent_text.Size = new System.Drawing.Size(250, 107);
            this.sent_text.TabIndex = 0;
            // 
            // CubeX2000
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(433, 245);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.statusStrip1);
            this.Name = "CubeX2000";
            this.Text = "CubeX2000";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel status_label;
        private System.Windows.Forms.ToolStripProgressBar ProgressBar;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button disconnect_button;
        private System.Windows.Forms.Button connect_button;
        public System.Windows.Forms.ComboBox PortsList;
        public System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.Button button_0;
        private System.Windows.Forms.Button button_3;
        private System.Windows.Forms.Button button_6;
        private System.Windows.Forms.Button button_9;
        private System.Windows.Forms.Button button_2;
        private System.Windows.Forms.Button button_5;
        private System.Windows.Forms.Button button_8;
        private System.Windows.Forms.Button button_1;
        private System.Windows.Forms.Button button_4;
        private System.Windows.Forms.Button button_7;
        public System.Windows.Forms.TextBox sent_text;
    }
}

