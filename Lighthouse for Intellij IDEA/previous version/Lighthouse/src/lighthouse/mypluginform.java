package lighthouse;

import com.intellij.openapi.project.Project;
import com.intellij.openapi.wm.ToolWindow;
import com.intellij.openapi.wm.ToolWindowFactory;
import com.intellij.psi.*;
import com.intellij.ui.components.JBScrollPane;
import com.intellij.ui.content.Content;
import com.intellij.ui.content.ContentFactory;
import com.intellij.uiDesigner.core.GridConstraints;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import java.util.ArrayList;

/**
 * Created by 노성훈 on 2016-12-31.
 */
public class mypluginform implements ToolWindowFactory{
    private CustomList list1 = new CustomList();
    private CustomList list2 = new CustomList();
    private CustomList list3 = new CustomList();
    private CustomList list4 = new CustomList();
    private JPanel myToolWindowContent;
    private JPanel Panel1;
    private JPanel Panel2;
    private JPanel Panel3;
    private JPanel Panel4;
    private JPanel Panel2_bottom;
    private JPanel Panel3_bottom;
    private JPanel Panel4_bottom;


    private void init_lists_scroll(JList list,JPanel panel){
        JScrollPane scrollPane = new JBScrollPane(list,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
                ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        GridConstraints temp = new GridConstraints();
        temp.setFill(GridConstraints.FILL_VERTICAL|GridConstraints.FILL_HORIZONTAL);
        panel.add(scrollPane);
        scrollPane.setVisible(true);

    }

    private void init_toolbar(){
        JToolBar Panel2_Toolbar = new ToggleButtons_panel(list2);
        Panel2_bottom.add(Panel2_Toolbar);
        JToolBar Panel3_Toolbar = new ToggleButtons_panel(list3);
        Panel3_bottom.add(Panel3_Toolbar);
        JToolBar Panel4_Toolbar = new ToggleButtons_panel(list4);
        Panel4_bottom.add(Panel4_Toolbar);
    }

    private void init_packagelists(Project project) {
        PsiPackage pack = JavaPsiFacade.getInstance(project).findPackage("");
        PsiPackage[] psiPackages = pack.getSubPackages();

        DefaultListModel dlm = new DefaultListModel();

        for (PsiPackage one_package : psiPackages) {
            dlm.addElement(one_package);
        }

        list1.MakeModel(dlm);

    }


    private void list_selection_eventlistener_set(Project project){
        list1.addListSelectionListener((ListSelectionEvent arg0) -> {
            if(!arg0.getValueIsAdjusting())
                make_class_list(project, list1.getSelectedValues());
        });
        list2.addListSelectionListener((ListSelectionEvent arg0) -> {
            if(!arg0.getValueIsAdjusting()) {
                make_method_list(project, (PsiClass) list2.getSelectedValue());
                System.out.println(list2.getSelectedValue());
            }
        });
    }

    private void make_method_list(Project project,PsiClass pcls){
        DefaultListModel dlm = new DefaultListModel();
        try {
            PsiMethod[] methods = pcls.getMethods();

            for (PsiMethod method : methods) {
                dlm.addElement(method);
            }
            list3.MakeModel(dlm);
        }
        catch (Exception e) {

        }

        try {
            PsiField[] fields = pcls.getFields();
            DefaultListModel dlm2 = new DefaultListModel();
            for (PsiField field : fields) {
                dlm2.addElement(field);
            }
            list4.MakeModel(dlm2);
        }
        catch (Exception e){

        }

    }

    private void make_class_list(Project project,Object[] objs){
        ArrayList<PsiClass[]> classeslist = new ArrayList<PsiClass[]>();
        for(Object obj : objs) {
            classeslist.add(JavaPsiFacade.getInstance(project).findPackage(((PsiPackage) obj).getName()).getClasses());
        }

        DefaultListModel dlm = new DefaultListModel();
        for(PsiClass[] classes : classeslist) {
            for (PsiClass oneclass : classes) {
                dlm.addElement(oneclass);
                System.out.println(oneclass.getModifierList().toString());
            }
        }

        list2.MakeModel(dlm);
    }

    private void init_form_design(){
        Panel1.add(list1);
        list1.setSelectionMode(DefaultListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        Panel2.add(list2);
        Panel3.add(list3);
        Panel4.add(list4);
        init_lists_scroll(list1,Panel1);
        init_lists_scroll(list2,Panel2);
        init_lists_scroll(list3,Panel3);
        init_lists_scroll(list4,Panel4);
    }



    public void createToolWindowContent(Project project, ToolWindow toolWindow){
        init_form_design();
        init_toolbar();

        list_selection_eventlistener_set(project);

        ContentFactory contentFactory = ContentFactory.SERVICE.getInstance();
        Content content = contentFactory.createContent(myToolWindowContent, "", false);
        toolWindow.getContentManager().addContent(content);

        this.init_packagelists(project);
    }


    private void createUIComponents() {
        // TODO: place custom component creation code here

    }
}
