#include<bits/stdc++.h>
using namespace std;
int n=30;
void init(int i)
{
    string t="txt"+to_string(i)+".html";
    freopen(t.c_str(),"r",stdin);
    t="day"+to_string(i)+"_ans.html";
    freopen(t.c_str(),"w",stdout);
    printf( "<!DOCTYPE html>\n"
            "<html>\n"
            "\n"
            "<head>\n"
            "    <title>字形：第%d天答案</title>\n"
            "    <meta charset=\"utf-8\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
            "    <link rel=\"stylesheet\" href=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css\">\n"
            "    <script src=\"https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js\"></script>\n"
            "    <script src=\"../js/font_main.js\"></script>\n"
            "    <style>\n"
            "       span.WA {color: #FF0000;font-size: 25px}\n"
            "		span.AC {color: #1cad4d;font-size: 25px}\n"
            "		span.AL {color: #000000;font-size: 25px}\n"
            "    </style>\n"
            "</head>\n",i);
    printf( "<body>\n"
            "    <div id=\"dg\" style=\"z-index: 9999; position: fixed ! important; right: 0px; top: 0px;\">\n"
            "        <table width=\"100%%\" style=\"position: absolute; width:260px; right: 0px; top: 0px;\">\n"
            "            <button type=\"button\" class=\"btn btn-warning\" onclick=\"window.location.href = '../font.html'\">返回</button>\n"
            "        </table>"
            "    </div>"
            "    <div class=\"container\">\n"
            "       <h2>字形：第%d天答案</h2>\n",i);
}
int main()
{
    for(int i=1;i<=n;i++)
    {
        cin.clear();
        init(i);
        string s;
        int j=1;
        while(getline(cin,s))
        {
            printf( "        <div class=\"border\">\n"
                    "            <span class=\"AL\">%d.</span>",j);
            for(int k=0;k<s.length()-5;k+=3)
            {
                if(s[k+3]=='.')               
                {
                    printf("<span id=\"%d\" class=\"AC\">%s</span>\n",j,s.substr(s.length()-4,3).c_str());
                    k++;
                }
                else printf("<span class=\"AL\">%s</span>\n",s.substr(k,3).c_str());
            }
            printf("\n        </div>\n");

            j++;
        }
        printf( "        <br></br>\n"
                "        </div>\n"
                "        <br></br>\n"
                "        <script>judge(%d)</script>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "    </div>\n"
                "</body>\n"
                "</html>\n",i);
    }
    fclose(stdout);
}