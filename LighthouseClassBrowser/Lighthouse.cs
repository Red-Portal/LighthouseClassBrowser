//------------------------------------------------------------------------------
// <copyright file="Lighthouse.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System.Runtime.CompilerServices;

namespace LighthouseClassBrowser
{
    using System;
    using System.Runtime.InteropServices;
    using Microsoft.VisualStudio.Shell;
    using EnvDTE;
    using System.Collections.Generic;

    /// <summary>
    /// This class implements the tool window exposed by this package and hosts a user control.
    /// </summary>
    /// <remarks>
    /// In Visual Studio tool windows are composed of a frame (implemented by the shell) and a pane,
    /// usually implemented by the package implementer.
    /// <para>
    /// This class derives from the ToolWindowPane class provided from the MPF in order to use its
    /// implementation of the IVsUIElementPane interface.
    /// </para>
    /// </remarks>
    [Guid("2b98fb5b-0cf9-402a-817a-5dbf39aa3760")]
    public class Lighthouse : ToolWindowPane
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Lighthouse"/> class.
        /// </summary>
        private Lighthouse() : base(null)
        {
            this.Caption = "Lighthouse";

            // This is the user control hosted by the tool window; Note that, even if this class implements IDisposable,
            // we are not calling Dispose on this object. This is because ToolWindowPane calls Dispose on
            // the object returned by the Content property.
            this.Content = new LighthouseControl();
        }

        private static Lighthouse staticInstance = null;

        public static Lighthouse getLighthouse()
        {
            if (staticInstance == null)
                staticInstance = new Lighthouse();

            return staticInstance;
        }
    }
}
