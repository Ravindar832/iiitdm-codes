// cs20b1085 gugulothu ravindar
// implementation of calculator using java applet event handling
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
public class Calculator extends Applet implements ActionListener
{
    TextField input;
    //Function to add features to the frame
    public void init()
    {
	setBackground(Color.white);
	setLayout(null);
	int i;
	input = new TextField();
	input.setBounds(150,100,270,50);
	this.add(input);
	Button button[] = new Button[10];
	for(i=0;i<10;i++)
	{
	    button[i] = new Button(String.valueOf(9-i));
	    button[i].setBounds(150+((i%3)*60),150+((i/3)*60),60,60);
	    this.add(button[i]);
	    button[i].addActionListener(this);
	}
	Button dec=new Button(".");
	dec.setBounds(210,310,60,80);
	this.add(dec);
	dec.addActionListener(this);
 
	Button clear=new Button("C");
	clear.setBounds(270,310,60,80);
	this.add(clear);
	clear.addActionListener(this);
 
	Button operator[] = new Button[5];
	operator[0]=new Button("/");
	operator[1]=new Button("*");
	operator[2]=new Button("-");
	operator[3]=new Button("+");
	operator[4]=new Button("=");
	for(i=0;i<4;i++)
	{
	    operator[i].setBounds(330,150+(i*60),60,60);
	    this.add(operator[i]);
	    operator[i].addActionListener(this);
	}
	operator[4].setBounds(390,310,70,80);
	this.add(operator[4]);
	operator[4].addActionListener(this);
    }
    String num1="";
    String output="";
    String num2="";
    //Function to calculate the expression
    public void actionPerformed(ActionEvent e)
    {
	String button = e.getActionCommand();
        char ch = button.charAt(0);
	if(ch>='0' && ch<='9'|| ch=='.') 
	{ 
	    if (!output.equals("")) 
		num2 = num2 + button; 
	    else
		num1 = num1 + button;   
	    input.setText(num1+output+num2); 
	} 
	else if(ch=='C') 
	{ 
	    num1 = output = num2 = ""; 
	    input.setText(""); 
	}
	else if (ch =='=') 
	{ 
	    if(!num1.equals("") && !num2.equals(""))
	    {
		double temp;
		double n1=Double.parseDouble(num1);
		double n2=Double.parseDouble(num2);
		if(n2==0 && output.equals("/"))
		{
		    input.setText(num1+output+num2+" = Zero Division Error");
		    num1 = output = num2 = "";
		}
		else
		{
		    if (output.equals("+")) 
		        temp = n1 + n2; 
		    else if (output.equals("-")) 
		        temp = n1 - n2; 
		    else if (output.equals("/")) 
	  	        temp = n1/n2; 
		    else
		        temp = n1*n2; 
		    input.setText(num1+output+num2+" = "+temp); 
		    num1 = Double.toString(temp);
		    output = num2 = ""; 
	        }
            }
	    else
	    {
		num1 = output = num2 = ""; 
		input.setText("");
	    }
        } 
	else 
	{ 
	    if (output.equals("") || num2.equals("")) 
		output = button; 
	    else 
	    { 
		double temp;
		double n1=Double.parseDouble(num1);
		double n2=Double.parseDouble(num2);
		if(n2==0 && output.equals("/"))
		{
		    input.setText(num1+output+num2+" = Zero Division Error");
		    num1 = output = num2 = "";
		}
		else
		{
		    if (output.equals("+")) 
		        temp = n1 + n2; 
		    else if (output.equals("-")) 
		        temp = n1 - n2; 
		    else if (output.equals("/")) 
	  	        temp = n1/n2; 
		    else
		        temp = n1*n2; 
		    num1 = Double.toString(temp); 
		    output = button; 
		    num2 = ""; 
	        }
            }
	    input.setText(num1+output+num2);
        }
    }
}
/*
<applet code = Calculator.class width=600 height=600>
</applet>
*/
