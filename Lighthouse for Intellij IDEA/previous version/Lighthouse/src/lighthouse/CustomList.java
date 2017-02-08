package lighthouse;

import com.intellij.psi.PsiModifierListOwner;

import javax.swing.*;

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
