using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
        private object m_WindowControl;
        private ITextEdit m_Edit;

        internal EditorViewControl(IVsTextManager textManager, object windowControl)
        {
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

            m_Edit = view.TextBuffer.CreateEdit();
            intializeEvents();
        }

        private void intializeEvents()
        {
            m_View.TextBuffer.Changed += new EventHandler<TextContentChangedEventArgs>(eventTextBufferChange);
        }

        private void eventTextBufferChange(object sender, TextContentChangedEventArgs e)
        {
            
        }

        // Need to add a movecursor operation in here
    }
}
