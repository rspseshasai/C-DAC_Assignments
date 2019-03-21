<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Add.aspx.cs" Inherits="Sample.Add" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td><asp:Label ID="lblNum1" runat = "server" Text="Number1"></asp:Label></td>
                    <td><asp:TextBox ID="txtNum1" runat="server"></asp:TextBox></td>
                </tr>

                <tr>
                    <td><asp:Label ID="lblNum2" runat = "server" Text="Number2"></asp:Label></td>
                    <td><asp:TextBox ID="txtNum2" runat="server"></asp:TextBox></td>
                </tr>

                <tr>
                    <td colspan="2">
                        <asp:Button ID="btnAdd" runat="server" Text="Add" OnClick="btnAdd_Click" />
                        </td>
                </tr>

                <tr>
                    <td colspan="2">
                        <asp:Label ID="lblRes" runat="server" Text="Result" />
                        </td>
                </tr>

                </table>
        </div>
    </form>
</body>
</html>
