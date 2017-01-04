package myplugin;

import com.intellij.psi.PsiClass;
import com.intellij.psi.PsiElement;
import com.intellij.psi.PsiExpression;
import com.intellij.psi.PsiPackage;
import com.intellij.psi.util.PsiUtil;

import javax.swing.*;
import java.awt.*;

/**
 * Created by 노성훈 on 2017-01-04.
 */
public class CustomListRenderer extends DefaultListCellRenderer{

    public Component getListCellRendererComponent(
            JList list, Object value, int index, boolean isSelected, boolean cellHasFocus)
    {
        // I know DefaultListCellRenderer always returns a JLabel
        // super setups up all the defaults
        JLabel label = (JLabel)super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);

        String s =label.getText();
        label.setText(s.substring(s.lastIndexOf(":")+1));
        return label;

    }

}
