#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <filesystem>
#include <string>
#include <thread>
#include "cppwebdriver/WebDriver.h"

int main() {
    selenium::webdriver::ChromeOptions options;
    options.AddArgument("--log-level=3");
    options.AddArgument("user-data-dir=C:\\Users\\username\\AppData\\Local\\Google\\Chrome Beta\\User Data\\");
    options.SetBinaryLocation("C:\\Program Files\\Google\\Chrome Beta\\Application\\chrome.exe");
    options.AddExperimentalOption("detach", true);

    selenium::webdriver::WebDriver driver(selenium::webdriver::ChromeDriverManager::GetChromeDriverPath(), options);

    driver.Get("https://www.instagram.com/");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    driver.FindElement(selenium::webdriver::By::XPath("/html/body/div[2]/div/div/div[2]/div/div/div/div[1]/div[1]/div[1]/div/div/div/div/div[2]/div[7]/div")).Click();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    driver.FindElement(selenium::webdriver::By::XPath("/html/body/div[2]/div/div/div[3]/div/div/div[1]/div/div[3]/div/div/div/div/div[2]/div/div/div/div[2]/div[1]/div/div/div[2]/div/button")).Click();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::string ext = ").mp4";
    std::string fileloc = "C:\\Users\\username\\Desktop\\kir\\vid\\1";
    std::string desc = fileloc + ext;

    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 0;
    input.ki.wScan = 0;
    input.ki.dwFlags = KEYEVENTF_UNICODE;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    std::wstring wdesc(desc.begin(), desc.end());

    for (wchar_t c : wdesc) {
        input.ki.wScan = c;
        SendInput(1, &input, sizeof(INPUT));
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    input.ki.wVk = VK_RETURN;
    input.ki.wScan = 0;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::seconds(5));

    driver.FindElement(selenium::webdriver::By::XPath("/html/body/div[2]/div/div/div[3]/div/div/div[1]/div/div[3]/div/div/div/div/div[2]/div/div/div/div[2]/div[1]/div/div/div/div[1]/div/div[2]/div")).Click();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    driver.FindElement(selenium::webdriver::By::XPath("/html/body/div[2]/div/div/div[3]/div/div/div[1]/div/div[3]/div/div/div/div/div[2]/div/div/div/div[2]/div[1]/div/div/div/div[1]/div/div[1]/div/div[3]/div/div[2]")).Click();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::string hashtags = "text with hashtag #korea #stupid moon #fk pride";
    std::wstring whashtags(hashtags.begin(), hashtags.end());

    for (wchar_t c : whashtags) {
        input.ki.wScan = c;
        SendInput(1, &input, sizeof(INPUT));
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    input.ki.wVk = VK_RETURN;
    input.ki.wScan = 0;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::seconds(300));

    return 0;
}
