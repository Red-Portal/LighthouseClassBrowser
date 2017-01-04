package myplugin;

import org.apache.batik.util.gui.resource.JToolbarButton;

import javax.swing.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

/**
 * Created by 노성훈 on 2017-01-04.
 */
public class ToggleButtons_panel extends JToolBar {


    JToggleButton abstract_button= new JToggleButton("abstract");
    JToggleButton static_button= new JToggleButton("static");
    JToggleButton derived_button= new JToggleButton("derived");
    public ToggleButtons_panel(JList list){
        setFloatable(false);
        add(abstract_button);
        add(static_button);
        add(derived_button);
        abstract_button.addActionListener(e -> {
            JToggleButton tbtn = (JToggleButton)e.getSource();
            if(tbtn.isSelected()){
                System.out.println("hello");
            } else{
                System.out.println("button is not selected");
            }
        });

    }

}
