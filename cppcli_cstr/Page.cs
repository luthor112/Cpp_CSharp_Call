using System.Net; // WebClient
using System.Globalization; // CultureInfo

public class Page
{
    public static string GetData()
    {
        WebClient webClient = new WebClient();
        string rawData = webClient.DownloadString("http://www.vanenet.hu/");
        return rawData;
    }
}