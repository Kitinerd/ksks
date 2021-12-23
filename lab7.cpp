using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO;
using System.IO.Ports;



namespace Lr_2_ser
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

            string[] ports = SerialPort.GetPortNames();
            foreach (string comport in ports)
            {
                comboBox1.Items.Add(comport);
            }
            draw = new Draw(pictureBox1);
            label1.Visible = false;
            Thread myThread = new Thread(new ThreadStart(TimeUpd));
            myThread.Start();
        }
        string rdata;
        Draw draw;
        TimeZoneInfo localZone = TimeZoneInfo.Local;
        private void TimeUpd()
        {
            DateTime dateTime = DateTime.Now;
            while (true)
            {
                dateTime = DateTime.Now;
                setLabelSafe(label1, dateTime.ToLongTimeString().ToString() + "\n" + dateTime.ToLongDateString().ToString());
            }
        }

        private void ConnectUDP()
        {
            //draw = new Draw(pictureBox1);
            string info = "";
            int numF = 0;
            List<string> Par;

            setTextSafe(textBox1, rdata);
            ParseHash parseHash = new ParseHash();
            parseHash.GetHash(rdata);
            numF = parseHash.GetNum('|');
            parseHash.GetNum('?');
            Par = parseHash.GetParams();
            draw.ExFunc(numF, Par);
            //date = DateTime.Now;
            localZone = TimeZoneInfo.Local;
            setTextSafe(textBox2, draw.infoAnswer);
            info = draw.infoAnswer;

            label1.Visible = draw.TAnswer;

            byte[] sendBytes = Encoding.ASCII.GetBytes(textBox2.Text);
        }

        private void setLabelSafe(Label label1, string txt, bool add = false)
        {
            if (label1.InvokeRequired)
            {
                label1.Invoke(new Action(() => label1.Text = txt));
            }
            else
            {
                label1.Text = txt;
            }
        }

        private void setTextSafe(TextBox textBox, string txt, bool add = false)
        {
            if (textBox.InvokeRequired)
            {
                if (!add)
                {
                    textBox.Invoke(new Action(() => textBox.Text = txt));
                }
                else
                {
                    textBox.Invoke(new Action(() => textBox.Text += (txt + "\r\n")));
                }
            }
            else
            {
                if (!add)
                {
                    textBox.Text = txt;
                }
                else
                {
                    textBox.Text += (txt + "\r\n");
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        string a = "";
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            a = serialPort1.ReadExisting();



            this.Invoke(new EventHandler(DoUpdate));
        }
        private void DoUpdate(object s, EventArgs e)
        {
            if (a.Contains("*"))
            {
                rdata = a.Replace("&lt;", "<");
                rdata = rdata.Replace("&gt;", ">");
                //rdata = "|10|?6?<50,50,ZOB,#542542,1,48>*";
                ConnectUDP();
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBox1.SelectedItem.ToString();
            serialPort1.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine(textBox2.Text);
        }
    }
}
