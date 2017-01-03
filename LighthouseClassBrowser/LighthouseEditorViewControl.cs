using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms.VisualStyles;
using EnvDTE;
using Microsoft.VisualStudio.Editor;
using Microsoft.VisualStudio.PlatformUI;
using Microsoft.VisualStudio.Text;
using Microsoft.VisualStudio.Text.Editor;
using Microsoft.VisualStudio.TextManager.Interop;
using Microsoft.VisualStudio.Utilities;

namespace LighthouseClassBrowser
{
    [ContentType("code")]
    [TextViewRole(PredefinedTextViewRoles.Editable)]
    class EditorViewControl
    {
        private readonly IVsTextManager m_TextManager;
        private IWpfTextView m_View;
        private Lighthouse m_Lighthouse;
        private LighthouseControl m_WindowControl;
        private ITextEdit m_Edit;
        private Timer m_delay;

        internal EditorViewControl(IVsTextManager textManager, LighthouseControl windowControl, Lighthouse lighthouse)
        {
            m_Lighthouse = lighthouse;
            m_TextManager = textManager;
            m_WindowControl = windowControl;
            initializeView();
        }

        internal void initializeView()
        {
            IVsTextView activeView;
            m_TextManager.GetActiveView(1, null, out activeView);

            IWpfTextView view = null;
            IVsUserData userData = activeView as IVsUserData;

            if (null != userData)
            {
                object holder;
                Guid guidViewHost = DefGuidList.guidIWpfTextViewHost;
                userData.GetData(ref guidViewHost, out holder);
                var viewHost = (IWpfTextViewHost)holder;
                view = viewHost.TextView;
            }
            m_View = view;     // Check later if having a seperate view is really necessary

            if (view == null)
                return;
            intializeEvents();
        }

        private void intializeEvents()
        {
        }

        public void moveToCodeElement(CodeElement codeElement)
        {
            DTE dte = codeElement.DTE;

            if (codeElement.ProjectItem.Document == null)
                codeElement.ProjectItem.Open("{00000000-0000-0000-0000-000000000000}");

            codeElement.ProjectItem.Document.Activate();
            Window window = codeElement.ProjectItem.Document.ActiveWindow;

            TextSelection textSelection = window.Document.Selection as TextSelection;

            textSelection.MoveToPoint(codeElement.StartPoint);
        }
    }
}
