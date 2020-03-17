
import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.ScrollPaneConstants;

public class GUI extends JFrame {

    Parser parser;

    //Elementos Interfaz
    JTextArea codeArea;
    JScrollPane codeScroll;
    JPanelDibujo drawArea;
    JButton trazar, limpiar, limpiarDibujo, Demo, Demo2, Demo3, Demo4, Demo5, Demo6, Demo7, Demo8, Demo9, Demo10;

    public GUI() {

        super("Logos 4 kids");

        setSize(1900, 1600);
        getContentPane().setBackground(new Color(244, 204, 112));
        parser = new Parser();
        parser.symbolInst();

        //Dibujo
        drawArea = new JPanelDibujo();
        drawArea.setBounds(10, 10, 600, 800);
        drawArea.setBackground(new Color(255,255,255));
        add(drawArea);

        //Codigo
        codeArea = new JTextArea(20, 20);
        codeArea.setBackground(new Color(25, 149, 173));
        codeArea.setFont(new Font("Verdana", Font.PLAIN, 14));
        codeArea.setForeground(Color.WHITE);
        codeArea.setLineWrap(true);
        codeArea.setWrapStyleWord(true);
        codeArea.setTabSize(4);
        codeScroll = new JScrollPane(codeArea);
        codeScroll.setBounds(630, 10, 400, 300);
        add(codeScroll);

        //Boton TRAZAR
        trazar = new JButton("Dibujar");
        trazar.setBounds(630, 600, 400, 40);
        trazar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser.limpiar();
                if (parser.compilar(codeArea.getText())) {
                    drawArea.setCurrentState(parser.ejecutar());
                } else {
                    parser = new Parser();
                    parser.symbolInst();
                    drawArea.setCurrentState(parser.getCurrentState());
                }
                drawArea.repaint();
            }
        });
        add(trazar);

        //Boton LIMPIAR
        limpiar = new JButton("Limpiar Código");
        limpiar.setBounds(830, 650, 200, 40);
        limpiar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText(null);
            }
        });
        add(limpiar);
        
        //Boton LIMPIAR
        limpiarDibujo = new JButton("Limpiar Dibujo");
        limpiarDibujo.setBounds(630, 650, 200, 40);
        limpiarDibujo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser = new Parser();
                parser.symbolInst();
                drawArea.setCurrentState(parser.getCurrentState());
                drawArea.repaint();
            }
        });
        add(limpiarDibujo);
        
        //Boton Tutorial
        Demo = new JButton("Demo Poligonos");
        Demo.setBounds(630, 500, 200, 40);
        Demo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure poligono(){\n" +
"for (i=0;i<$1;i=i+1){\n" +
"COLOR[240*i,50*i,201*i];\n" +
"    AVANZA[200];\n" +
"    GIRA[$2];\n" +
"}\n" +
"}\n" +
"AVANZA[-100];\n" +
"GIRA[90];\n" +
"AVANZA[-270];\n" +
"GIRA[-90];\n" +
"poligono(9,40);\n" +
"poligono(8,45);\n" +
"poligono(7,51);\n" +
"poligono(6,60);\n" +
"poligono(5,72);\n" +
"poligono(4,90);\n" +
"poligono(3,120);\n" +
"");
            }
        });
        add(Demo);

        Demo2 = new JButton("Demo Personalizado.");
        Demo2.setBounds(830, 500, 200, 40);
        Demo2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure circulo(){\n"
                        + "   for(aux=0; aux<360; aux=aux+1){\n"
                        + "      COLOR[aux*13, aux*26, aux*51];\n"
                        + "      AVANZA[2];\n"
                        + "    \n"
                        + "     GIRA[2];\n"
                        + "   }\n"
                        + "}\n"
                        + "procedure cuadrados(){\n"
                        + "	for(i=0;i<4;i=i+1)\n"
                        + "	{\n"
                        + "		circulo(40,50,70);\n"
                        + "		GIRA[90];\n"
                        + "		circulo(40,50,70);\n"
                        + "		AVANZA[200];\n"
                        + "	}\n"
                        + "	\n"
                        + "}\n"
                        + "cuadrados();");
            }
        });
        add(Demo2);

        Demo3 = new JButton("Demo Hilbert");
        Demo3.setBounds(830, 550, 200, 40);
        Demo3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure hilbert(){\n" +
"	for(i=0; i<$1; i=i+1){\n" +
"	COLOR[231, 37, 18];\n" +
"	GIRA[$2];\n" +
"	hilbert($1-1,-$2);\n" +
"	AVANZA[10];\n" +
"	GIRA[-$2];\n" +
"	hilbert($1-1,$2);\n" +
"	AVANZA[10];\n" +
"	hilbert($1-1,$2);\n" +
"	GIRA[-$2];\n" +
"	AVANZA[10];\n" +
"	hilbert($1-1,-$2);\n" +
"	GIRA[$2];\n" +
"	}\n" +
"}\n" +
"AVANZA[-170];\n" +
"GIRA[-90];\n" +
"AVANZA[130];\n" +
"GIRA[90];\n" +
"hilbert(5,90);\n" +
"");
            }
        });
        add(Demo3);

        Demo4 = new JButton("Demo Árbol");
        Demo4.setBounds(630, 550, 200, 40);
        Demo4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("COLOR[87,166,057];\n" +
"GIRA[90];\n" +
"AVANZA[-100];\n" +
"GIRA[180+90];\n" +
"procedure arbol(){\n" +
"if($1>4){\n" +
"AVANZA[$1];\n" +
"GIRA[20];\n" +
"COLOR[87,166,057];\n" +
"arbol($1-4);\n" +
"GIRA[320];\n" +
"COLOR[87,166,057];\n" +
"arbol($1-4);\n" +
"GIRA[20];\n" +
"COLOR[87,166,057];\n" +
"AVANZA[(-1)*($1)];\n" +
"}\n" +
"}\n" +
"GIRA[90];\n" +
"COLOR[87,166,057];\n" +
"GIRA[180];\n" +
"AVANZA[100];\n" +
"GIRA[180];\n" +
"COLOR[87,166,057];\n" +
"arbol(50);\n" +
"");
            }
        });
        add(Demo4);

        Demo5 = new JButton("Demo Estrella");
        Demo5.setBounds(630, 450, 200, 40);
        Demo5.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure poligono(){\n" +
"for (i=0;i<$1;i=i+1){\n" +
"COLOR[140+i,150+i,201+i];\n" +
"    AVANZA[300];\n" +
"    GIRA[$2];\n" +
"}\n" +
"}\n" +
"procedure gira(){\n" +
"AVANZA[300];\n" +
"GIRA[90];\n" +
"AVANZA[170];\n" +
"GIRA[90];\n" +
"}\n" +
"AVANZA[-150];\n" +
"gira();\n" +
"poligono(3,120);\n" +
"gira();\n" +
"poligono(3,120);\n" +
"");
            }
        });
        add(Demo5);

        Demo6 = new JButton("Demo Pentagrama");
        Demo6.setBounds(830, 450, 200, 40);
        Demo6.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("for (i=0;i<40;i=i+1){\n" +
"COLOR[i*240,0,0];\n" +
"    AVANZA[i*10];\n" +
"    GIRA[144];\n" +
"}");
            }
        });
        add(Demo6);

        Demo7 = new JButton("Demo Koch");
        Demo7.setBounds(830, 400, 200, 40);
        Demo7.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure snowflake(){\n" +
"snow2();\n" +
"	GIRA[60];\n" +
"snow2();\n" +
"	GIRA[-120];\n" +
"snow2();\n" +
"	GIRA[60];\n" +
"snow2();\n" +
"}\n" +
"procedure snow2(){\n" +
"snow3();\n" +
"	GIRA[60];\n" +
"snow3();\n" +
"	GIRA[-120];\n" +
"snow3();\n" +
"	GIRA[60];\n" +
"snow3();\n" +
"}\n" +
"procedure snow3(){\n" +
"snow4();\n" +
"	GIRA[60];\n" +
"snow4();\n" +
"	GIRA[-120];\n" +
"snow4();\n" +
"	GIRA[60];\n" +
"snow4();\n" +
"}\n" +
"procedure snow4(){\n" +
"COLOR[0,127,253];\n" +
"AVANZA[5];\n" +
"	GIRA[60];\n" +
"AVANZA[5];\n" +
"	GIRA[-120];\n" +
"AVANZA[5];\n" +
"	GIRA[60];\n" +
"AVANZA[5];\n" +
"}\n" +
"AVANZA[-100];\n" +
"GIRA[90];\n" +
"AVANZA[-200];\n" +
"snowflake();\n" +
"GIRA[-120];\n" +
"snowflake();\n" +
"GIRA[-120];\n" +
"snowflake();\n" +
"");
            }
        });
        add(Demo7);

        Demo8 = new JButton("Demo Regla");
        Demo8.setBounds(630, 400, 200, 40);
        Demo8.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("AVANZA[-200];\n" +
"for(i=0;i<40;i=i+1){\n" +
"COLOR[i*13, i*26, i*51];\n" +
"AVANZA[10];\n" +
"GIRA[90];\n" +
"AVANZA[5];\n" +
"GIRA[180];\n" +
"AVANZA[10];\n" +
"GIRA[180];\n" +
"AVANZA[5];\n" +
"GIRA[-90];\n" +
"}       ");
            }
        });
        add(Demo8);

        Demo9 = new JButton("Demo Espirografo 1");
        Demo9.setBounds(630, 350, 200, 40);
        Demo9.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure espirografo(){\n"
                        + "	for(i=0;i<200;i=i+1){\n"
                        + "	COLOR[0, i*26, i*51];\n"
                        + "	AVANZA[i*4];\n"
                        + "	GIRA[145];\n"
                        + "}\n"
                        + "}\n"
                        + "\n"
                        + "espirografo();");
            }
        });
        add(Demo9);

        Demo10 = new JButton("Demo Espirografo 2");
        Demo10.setBounds(830, 350, 200, 40);
        Demo10.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText("procedure circulo(){\n"
                        + "	for(i=0;i<366;i=i+1){\n"
                        + "	AVANZA[2];\n"
                        + "	GIRA[1];\n"
                        + "}\n"
                        + "}\n"
                        + "\n"
                        + "procedure espirografo2(){\n"
                        + "	for(j=0;j<45;j=j+1){\n"
                        + "	COLOR[j*30, j*40, j*20];\n"
                        + "	circulo();\n"
                        + "	GIRA[90];\n"
                        + "}\n"
                        + "}\n"
                        + "\n"
                        + "espirografo2();");
            }
        });
        add(Demo10);

        this.setLayout(null);
        this.setBounds(50, 50, 1100, 849);
        this.setVisible(true);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

}
