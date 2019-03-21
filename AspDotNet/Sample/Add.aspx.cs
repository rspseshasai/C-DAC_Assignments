using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Sample
{
    public partial class Add : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnAdd_Click(object sender, EventArgs e)
        {
            int a, b, c;
            a = int.Parse(txtNum1.Text);
            b = int.Parse(txtNum2.Text);
            c = addNums(a, b);
            lblRes.Text = c.ToString();
        }

        private int addNums(int i, int j)
        {
            return i + j;
        }
    }
}