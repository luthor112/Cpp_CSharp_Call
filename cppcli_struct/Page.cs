using System.Net; // WebClient
using System.Globalization; // CultureInfo

namespace PageGetter
{
    public struct PageData
    {
        public string PageUrl { get; set; }
        public string PageText { get; set; }
    }

    public class Page
    {
        public PageData GetData()
        {
            WebClient webClient = new WebClient();
            string rawData = webClient.DownloadString("http://www.vanenet.hu/");
            
            return new PageData
            {
                PageUrl = "http://www.vanenet.hu/",
                PageText = rawData
            };
        }
    }
}