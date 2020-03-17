package vista;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import modelo.compilador.Parser;

public class VentanaPrincipal extends JFrame {

    JTextArea areaDeCodigo;
    JScrollPane scrollCodigo,scrollDibujo;
    PanelDeDibujo panelDeDibujo;
    JButton ejecutar;
    Parser parser;
    public static final Color accent = new Color(0x0860A5);
    
    
    public VentanaPrincipal(){
        JPanel top = new JPanel();
        top.setBackground(accent);
        top.setBounds(0,0,850,50);
        add(top);

        ejecutar = new JButton("Dibujar Figura");
        ejecutar.setBounds(300,50,300,50);
        add(ejecutar);
                      
        parser = new Parser();
        parser.insertarInstrucciones();
        
        areaDeCodigo = new JTextArea();
        areaDeCodigo.setBounds(10,10, 850, 250);
        areaDeCodigo.setFont(new Font("Consolas", Font.PLAIN, 12));
        areaDeCodigo.setForeground(Color.BLACK);
        scrollCodigo = new JScrollPane (areaDeCodigo);
        scrollCodigo.setBorder(BorderFactory.createEmptyBorder());
        scrollCodigo.setBounds(0,100,850,100);        
        add(scrollCodigo);
        
        panelDeDibujo = new PanelDeDibujo();
        panelDeDibujo.setPreferredSize(new Dimension(1000,1500));
        scrollDibujo = new JScrollPane(panelDeDibujo);
        scrollDibujo.setBorder(BorderFactory.createEmptyBorder());
        scrollDibujo.setBounds(0,200,850,900); 
        scrollDibujo.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollDibujo.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        add(scrollDibujo);

        ejecutar.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae) {
                             parser.limpiar();
                if(parser.compilar(areaDeCodigo.getText()))
                    panelDeDibujo.setConfiguracion(parser.ejecutar());
                else{
                    parser = new Parser();
                    parser.insertarInstrucciones();
                    panelDeDibujo.setConfiguracion(parser.getConfiguracion());
                }
                panelDeDibujo.repaint();

            }
        });
        
        JLabel title = new JLabel("Escribe el codigo en el TextArea y presiona el boton.");
        title.setFont(new Font("Arial", Font.PLAIN, 16));
        title.setForeground(Color.WHITE);
        top.add(title, BorderLayout.WEST);
        
        setLayout(null);
        setBounds(300,20,855,700);
        setVisible(true);
        setTitle("Figuras");
        //getContentPane().setBackground(new Color(0x000000));
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        setPreferredSize(new Dimension(865,680));
        pack();
    }
}