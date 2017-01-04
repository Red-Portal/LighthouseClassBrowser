package myplugin;

import com.intellij.psi.PsiElement;
import com.intellij.psi.PsiModifierList;
import com.intellij.psi.PsiModifierListOwner;
import com.intellij.psi.PsiTarget;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.util.ArrayList;

/**
 * Created by 노성훈 on 2017-01-04.
 */
public class CustomList extends JList {
    private DefaultListModel staticdlm = new DefaultListModel();
    public CustomList(){
        setSelectionMode(DefaultListSelectionModel.SINGLE_SELECTION);
        setCellRenderer(new CustomListRenderer());

    }

    public void MakeModel(DefaultListModel dlm){
        staticdlm = dlm;
        setModel(dlm);
    }

    public void check(String[] strs){
        PsiModifierListOwner[] staticarrays =  (PsiModifierListOwner[]) staticdlm.toArray();
        for(PsiModifierListOwner modiferlist : staticarrays) {
            for (String str : strs) {
                if (modiferlist.hasModifierProperty(str)) {

                }
            }
        }
    }
}
