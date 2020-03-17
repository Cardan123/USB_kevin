import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Colcha {

	public final static int SHOW_SIZE = 100;

	int alto;
	int ancho;
	BufferedImage[][] mat;
	char[][] matDir;

	public Colcha(int m, int n) {
		alto = n;
		ancho = m;
		matDir = new char[m][n];
		mat = new BufferedImage[m][n];
	}

	public void setMatDir(char[][] matDir) {
		for (int j = 0; j < alto; j++)
			for (int i = 0; i < ancho; i++)
				this.matDir[i][j] = matDir[i][j];
	}

	public void setMat(BufferedImage[][] mat, char[][] matDir) {
		for (int j = 0; j < alto; j++) {
			for (int i = 0; i < ancho; i++) {
				this.mat[i][j] = mat[i][j];
				this.matDir[i][j] = matDir[i][j];
			}
		}
	}

	public void print() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				System.out.print((int)matDir[j][i]);
			}
			System.out.println();
		}
	}

	public Colcha clone() {
		Colcha colcha = new Colcha(ancho, alto);
		colcha.setMat(this.mat, this.matDir);
		return colcha;
	}

	public static Colcha rota() {
		Colcha cNueva = new Colcha(alto, ancho);
		for (int i = 0; i < c.alto; i++) {
			for (int j = 0; j < c.ancho; j++) {
				BufferedImage pI = c.mat[j][i];
				char p = c.matDir[j][i];
				char m;
				switch(p) {
					case 0:	m = 1;	break;
					case 1:	m = 2;	break;
					case 2:	m = 3;	break;
					case 3:	m = 0;	break;
					default:	m = p;
				}
				cNueva.matDir[c.alto-i-1][j] = m;
				cNueva.mat[c.alto-i-1][j] = pI;
			}
		}
		return cNueva;
	}

	public static Colcha cose(Colcha c1, Colcha c2) {
		if (c1.alto != c2.alto) // -- Error semantico
			Machine.execerror("Cosiendo colchas incompatibles! "+c1.alto +" "+c2.alto);
		Colcha colcha = new Colcha(c1.ancho + c2.ancho, c1.alto);
		for (int i = 0; i < colcha.alto; i++) {
			for (int j = 0; j < colcha.ancho; j++) {
				if (j < c1.ancho) {
					colcha.matDir[j][i] = c1.matDir[j][i];
					colcha.mat[j][i] = c1.mat[j][i];
				} else {
					colcha.matDir[j][i] = c2.matDir[j-c1.ancho][i];
					colcha.mat[j][i] = c2.mat[j-c1.ancho][i];
				}
			}
		}

		return colcha;
	}

	public static Colcha A() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/0.jpg");
		return colcha;
	}

	public static Colcha B() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/1.png");
		return colcha;
	}

	public static Colcha C() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/2.jpg");
		return colcha;
	}

	public static Colcha D() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/3.jpg");
		return colcha;
	}

	public static Colcha E() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/4.png");
		return colcha;
	}

	public static Colcha F() {
		Colcha colcha = new Colcha(1,1);
		colcha.matDir[0][0] = 0;
		colcha.mat[0][0] = cargarImagen("Images/Default/5.png");
		return colcha;
	}

	public static double ancho(Colcha c) {
		return c.ancho;
	}

	public static double alto(Colcha c) {
		return c.alto;
	}

	public static Colcha cargaColcha(String fileDir) {
		//System.out.println("Archivo: "+fileDir);
		Colcha c = new Colcha(1,1);
		c.mat[0][0] = cargarImagen(fileDir);
		return c;
	}

	public static BufferedImage cargarImagen(String fileDir) {
		File f  = new File(fileDir);
		BufferedImage img = null;
		try {
			img = ImageIO.read(f);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return img;
	}

	public static Colcha pieza(Colcha colcha, double x, double y) {
		Colcha c = new Colcha(1,1);
		c.matDir[0][0] = colcha.matDir[(int)y][(int)x];
		return c;
	}

	public static void mostrarColcha(Colcha colcha) {
		JFrame frame = new JFrame();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel = new JPanel();
		GridBagLayout layout = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();
		//c.gridwidth = colcha.ancho;
		//c.gridheight = colcha.alto;
		c.weightx = 0;
		c.weighty = 0;
		c.anchor = GridBagConstraints.FIRST_LINE_START;
		//GridLayout layout = new GridLayout(colcha.alto, colcha.ancho, 0, 0);
		panel.setSize(colcha.ancho * SHOW_SIZE, colcha.alto*SHOW_SIZE);
		panel.setLayout(layout);
		panel.setBackground(Color.DARK_GRAY);
		for (int j = 0; j < colcha.alto; j++) {
			for (int i = 0; i < colcha.ancho; i++) {
				BufferedImage buff = new BufferedImage(SHOW_SIZE, SHOW_SIZE, BufferedImage.TYPE_INT_ARGB);
				Graphics2D g2d = buff.createGraphics();
				AffineTransform transform = new AffineTransform();//AffineTransform.getTranslateInstance(-colcha.mat[i][j].getWidth()/2, -colcha.mat[i][j].getHeight()/2);//AffineTransform.getRotateInstance(colcha.matDir[i][j]*Math.PI/2, SHOW_SIZE/2, SHOW_SIZE/2);
				//transform.translate(-colcha.mat[i][j].getWidth()/2, -colcha.mat[i][j].getHeight()/2);
				transform.scale((float)SHOW_SIZE/colcha.mat[i][j].getWidth(), (float)SHOW_SIZE/colcha.mat[i][j].getHeight());
				//transform.scale(0.5,0.5);
				//transform.translate(SHOW_SIZE/2, SHOW_SIZE/2);
				//transform.scale(0.5, 0.5);
				transform.rotate(colcha.matDir[i][j]*Math.PI/2,colcha.mat[i][j].getWidth()/2,colcha.mat[i][j].getHeight()/2);
				//
				//transform.translate(SHOW_SIZE/2, SHOW_SIZE/2);
				g2d.drawImage(colcha.mat[i][j], transform, null);
				JLabel label = new JLabel(new ImageIcon(buff));
				label.setSize(SHOW_SIZE, SHOW_SIZE);
				c.gridx = i;
				c.gridy = j;
				layout.setConstraints(label,c);
				panel.add(label);
			}
		}
		frame.add(panel);
		frame.pack();
		//panel.setLa
	}
}
