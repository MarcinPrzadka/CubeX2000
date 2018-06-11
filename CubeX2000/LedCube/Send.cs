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
    class Send : Form, ISend
    {
        private static Send instance;
        public CubeX2000 Cube;

        private Send() { }

        public static Send Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new Send();
                }
                return instance;
            }
        }

        public void SendToSerial(string liczba)
        {
            Cube.serialPort.WriteLine(liczba);
            Cube.sent_text.Text += liczba;
        }

    }
}
