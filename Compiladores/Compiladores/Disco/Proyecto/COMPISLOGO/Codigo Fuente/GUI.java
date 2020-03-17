



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
    JButton trazar,limpiar,limpiarDibujo;
    
    public GUI(){
        
        super("Logo");
        
        
        parser = new Parser();
        parser.symbolInst();
                
        //Dibujo
        drawArea = new JPanelDibujo();
        drawArea.setBounds(10,10,600,600);
        drawArea.setBackground(new Color(255,255,255));
        add(drawArea);
        
        //Codigo
        codeArea = new JTextArea(20,20);
        codeArea.setBackground(Color.BLACK);
        codeArea.setFont(new Font("Arial", Font.PLAIN, 14));
        codeArea.setForeground(Color.WHITE);
        codeArea.setLineWrap(true);
        codeArea.setWrapStyleWord(true);
        codeArea.setTabSize(4);
        codeScroll = new JScrollPane (codeArea);
        codeScroll.setBounds(630,10,400,400);
        add(codeScroll);
        
        //Boton TRAZAR
        trazar = new JButton("Trazar");
        trazar.setBounds(630,450,400,40);
        trazar.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser.limpiar();
                if(parser.compilar(codeArea.getText()))
                    drawArea.setCurrentState(parser.ejecutar());
                else{
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
        limpiar.setBounds(630,500,400,40);
        limpiar.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText(null);
            }
        });
        add(limpiar);
        
        //Boton LIMPIAR
        limpiarDibujo = new JButton("Limpiar Dibujo");
        limpiarDibujo.setBounds(630,550,400,40);
        limpiarDibujo.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser = new Parser();
                parser.symbolInst();
                drawArea.setCurrentState(parser.getCurrentState());
                drawArea.repaint();
            }
        });
        add(limpiarDibujo);
        
        this.setLayout(null);
        this.setBounds(50,50,1050,649);
        this.setVisible(true);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        
    }
    
}
