int inputX = A1;
int inputY = A2;
int width = A3;
int height = A4;

int button[] = {13, 12, 11};
int buttonCount = 3;

String commands[] = {
    "clear display",
    "draw pixel",
    "draw line",
    "draw rectangle",
    "fill rectangle",
    "draw ellipse",
    "fill ellipse",
    "draw circle",
    "fill circle",
    "Time",
    "DRAWText",
    "DRAWChar",
    "Begushaya str"};

void setup()
{
    pinMode(A0, OUTPUT);
    pinMode(inputX, INPUT);
    pinMode(inputY, INPUT);
    pinMode(width, INPUT);
    pinMode(height, INPUT);
    for (int i = 0; i <= buttonCount - 1; i++)
    {
        pinMode(button[i], INPUT);
    }

    Serial.begin(9600);
}
bool show = false, s = false;
int index;
String text;
String color;
void loop()
{
    if (index > 12 || index < 0)
    {
        index = 0;
    }
    if (digitalRead(button[0]) == 1 && !show)
    {
        index--;
        show = true;
        s = false;
    }
    if (digitalRead(button[1]) == 1 && !show)
    {
        index++;
        show = true;
        s = false;
    }
    if (show && digitalRead(button[1]) == 0 && digitalRead(button[0]) == 0)
    {
        Serial.println(commands[index]);
        show = false;
    }
    if (digitalRead(button[2]) == 1 && !s)
    {
        color = "#" + String(analogRead(inputX) % 8) + String(analogRead(inputY) % 8) + String(analogRead(width) % 8) + String(analogRead(inputX) % 8) + String(analogRead(inputY) % 8) + String(analogRead(width) % 8);
        if (index == 0)
        {

            text = "|0|?1?<";
            text += color;
            text += ">";
        }
        else if (index == 1)
        {
            text = "|1|?3?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(color) + ">";
        }
        else if (index == 2)
        {
            text = String("|2|?5?<") + String(analogRead(inputX)) + String(",") + String(analogRead(inputY)) + String(",") + String(analogRead(width)) + String(",") + String(analogRead(height)) + String(",#abfced>");
        }
        else if (index == 3)
        {

            text = "|3|?5?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(analogRead(height)) + "," + String(color) + ">";
        }
        else if (index == 4)
        {

            text = "|4|?5?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(analogRead(height)) + "," + String(color) + ">";
        }
        else if (index == 5)
        {

            text = "|5|?5?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(analogRead(height)) + "," + String(color) + ">";
        }
        else if (index == 6)
        {

            text = "|6|?5?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(analogRead(height)) + "," + String(color) + ">";
        }
        else if (index == 7)
        {
            text = "|7|?4?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(color) + ">";
        }
        else if (index == 8)
        {

            text = "|8|?4?<" + String(analogRead(inputX)) + "," + String(analogRead(inputY)) + "," + String(analogRead(width)) + "," + String(color) + ">";
        }
        else if (index == 9)
        {
            text = "|9|?1?<" + color + ">";
        }
        else if (index == 10)
        {
            String strText = "SLAVA UKRAINE";
            text = "|10|?6?<50,50," + String(strText) + "," + String(color) + ",1,48>";
        }
        else if (index == 11)
        {
            String strText = "ABOBA";
            strText = strText[0];
            text = "|11|?6?<50,50," + String(strText) + "," + String(color) + ",1,72>";
        }
        else if (index == 12)
        {
            String strText = "SLAVA UKRAINE";
            text = "|12|?6?<50,50," + String(strText) + "," + String(color) + ",1,48>";
        }
        else
        {
            text = "|0|?1?<#ff00aa>";
        }

        Serial.println(text + "*");
        s = true;
    }

    parse();
}

void parse()
{
    String data = "";
    if (Serial.available() > 0)
    {
        data = Serial.readString();
        Serial.println(data);
    }
}
