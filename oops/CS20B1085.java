// cs20b1085 gugulothu ravindar
// java program to draw a ellipse
// using drawOval function.
// java program to draw a ellipse
// using drawOval function.
import java.awt.*;
import javax.swing.*;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Label;
public class CS20B1085 extends JApplet {

	public void init()
	{
		// set size
		setSize(1024, 720);

		repaint();
	}

	// paint the applet
	public void paint(Graphics g)
	{
		// draw oval
		g.drawOval(772,0,253,180);
		g.drawOval(820,50,150,100);
		g.setColor(Color.pink);
		g.fillOval(820,50,150,100);
		//g.drawString("RAVINDAR",462,365);
        //g.setColor(Color.blue);

		// draw rectangle
		//outer
		g.setColor(Color.yellow);
		g.drawRect(0,520, 180, 200);
		g.fillRect(0,520, 180, 200);
        // inner
		g.setColor(Color.red);
		g.drawRect(40,570, 120, 100);


		//draw circle
		g.drawOval(412,260,200,200);
		g.setColor(Color.green);
		g.fillOval(412,260,200,200);
        
		// label
		Font myFont = new Font("Verdana", Font.BOLD,20);
		g.setFont(myFont);
		g.setColor(Color.blue);
		g.drawString("ravindar",470,365);

	}
}

/*
  <applet code="CS20B1085.class" width="1024" height="720"></applet>
  */