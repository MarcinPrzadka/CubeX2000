using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace LedCube
{
    public partial class CubeX2000 : Form
    {
        private Send Send;
        private SerialConnector SC;


        public CubeX2000()
        {
            InitializeComponent();
            getPortNames();                                         // Pobranie listy portów - działa
            //String[] AvaliblePorts = SerialPort.GetPortNames();   //  Pobranie listy portów -  nie działa
            //SC.getPortNames(AvaliblePorts);                       //  Pobranie listy portów -  nie działa
        }

        void getPortNames()
        {
            String[] AvaliblePorts = SerialPort.GetPortNames();
            PortsList.Items.AddRange(AvaliblePorts);
        }
        
        private void connect_button_Click(object sender, EventArgs e)
        {
            try
            {
                if(PortsList.Text == "")
                {
                    status_label.Text = "Select Serial Port!";
                }
                else
                {
                    status_label.Text = "Connected!";
                    serialPort.PortName = PortsList.Text;
                    serialPort.BaudRate = 9600;
                    serialPort.Open();
                    ProgressBar.Value = 100;
                    connect_button.Enabled = false;
                    disconnect_button.Enabled = true;
                    PortsList.Enabled = false;
                    groupBox2.Enabled = true;
                }   
            }
            catch(UnauthorizedAccessException)
            {
                status_label.Text = "Unauthorized Access!"; 
            }
        }

        private void send_button_Click(object sender, EventArgs e)
        {
            string liczba = (sender as Button).Text;
            //Send.SendToSerial(liczba);                      // Przesłanie na serialPort -  nie działa
            serialPort.WriteLine((sender as Button).Text);    // Przesłanie na serialPort -  działa
            sent_text.Text += (sender as Button).Text;        //Przesłanie na serialPort -   działa

        }

        private void disconnect_button_Click(object sender, EventArgs e)
        {
            serialPort.Close();
            ProgressBar.Value = 0;
            connect_button.Enabled = true;
            disconnect_button.Enabled = false;
            status_label.Text = "Disconnected";
            PortsList.Enabled = true;
            groupBox2.Enabled = false;
        }
    }
}
