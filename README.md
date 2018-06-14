# Vaynerclock
Countdown timer (24-hour format) that only considers hours left until bedtime.

![garyv](https://user-images.githubusercontent.com/6345197/41390208-401e08b8-6f5a-11e8-99fd-aee21945d56a.png)

### Why?
One day while going through Instagram I saw a video from [Gary Vaynerchuk](https://en.wikipedia.org/wiki/Gary_Vaynerchuk) talking about the fact that people always complain that they don't have enough hours during the day.

The message of this short [video](https://www.youtube.com/watch?v=edMfu5IILSI) got stuck in my head. It sounds so obvious but well...we do not have 24 hours during the day, since roughly 1/3 of that has to be subtracted from the time we spend sleeping. If you sleep 6 hours a day, you end up with the magic number: 18.

### What does this little thing do?

So since I had a DS3231 and a 5110 hanging around on my desk (and a UNO of course :blush:), I decided to create a clock that would count the hours left until my bedtime.

It's as simple as this: if it's 7 PM and I go to sleep at 11 PM, the clock shows the number 4. If it's 4 PM then I'd see 7 (check image below).

### Connections
<img width="383" alt="schema" src="https://user-images.githubusercontent.com/6345197/41390866-39056172-6f5d-11e8-9bed-ddb251335653.png">

### Circuit working

Now everytime I come by my desk, I can check how many hours I have left...good reminder not to waste them watching House of Cards :joy: (please check the video lol)

<img width="407" alt="schema" src="https://user-images.githubusercontent.com/6345197/41391094-5385eef8-6f5e-11e8-9b14-7c5d6bbe1c47.JPG">

### Instructions

In order to run it, you'll need to include both `RTClib.h` and `U8glib.h` libraries. 

**IMPORTANT:** the `setTime` function only runs the very first time you upload the sketch to the board. Also, since the DS3231 has an internal RTC (very precise, btw) and it will keep counting the hours (UTC) even if the Arduino doesn't have power.

Have fun! :v:
