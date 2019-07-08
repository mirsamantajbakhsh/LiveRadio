
# Live Radio
Broadcast from your Android device. Live Radio is a audio streaming library based on CoolMicApp (default IceCast Android Client), for making the life easier. The detailed explanation is available at [my personal blog](https://mstajbakhsh.ir/broadcast-yourself-through-android/).

![Test](https://github.com/mirsamantajbakhsh/LiveRadio/raw/master/ScreenShots/Live%20Audio%20Library.PNG)

# How to Use

For using the Live Audio library, you need to start a stream server, and then connect your application to the server.

## Starting Stream Server
I've used [IceCast](https://icecast.org/) as the media server on Ubuntu 18.04 LTS. I've added a new **stream source** to the IceCast config file (`/etc/icecast2/icecast.xml`) using these settings:
<pre>&lt;mount type="normal"&gt;
    &lt;mount-name&gt;<strong>/harleyquinn</strong>&lt;/mount-name&gt;
    &lt;username&gt;<strong>joker</strong>&lt;/username&gt;
    &lt;password&gt;<strong>hackme</strong>&lt;/password&gt;
    &lt;max-listeners&gt;2&lt;/max-listeners&gt;
    &lt;max-listener-duration&gt;360000&lt;/max-listener-duration&gt;
    &lt;dump-file&gt;/tmp/harley.ogg&lt;/dump-file&gt;
    &lt;charset&gt;ISO8859-1&lt;/charset&gt;
    &lt;public&gt;1&lt;/public&gt;
    &lt;stream-name&gt;<strong>Harley Quinn Radio</strong>&lt;/stream-name&gt;
    &lt;stream-description&gt;<strong>Listen to my live audio from Gotham! With Joker!</strong>&lt;/stream-description&gt;
    &lt;genre&gt;Heavy&lt;/genre&gt;
    &lt;bitrate&gt;64&lt;/bitrate&gt;
    &lt;type&gt;application/ogg&lt;/type&gt;
    &lt;subtype&gt;vorbis&lt;/subtype&gt;
    &lt;hidden&gt;1&lt;/hidden&gt;
    &lt;burst-size&gt;65536&lt;/burst-size&gt;
    &lt;mp3-metadata-interval&gt;4096&lt;/mp3-metadata-interval&gt;
    &lt;on-connect&gt;/home/icecast/bin/source-start&lt;/on-connect&gt;
    &lt;on-disconnect&gt;/home/icecast/bin/source-end&lt;/on-disconnect&gt;
&lt;/mount&gt;
</pre>

## Add Dependency
The code is published as an AAR library. Therefore, you can add the following dependency to your Android project:
`implement 'ir.mstajbakhsh.android:LiveAudio:1.0.0'`

## Permissions
Add the following permissions to your `Manifest.xml`:
```java
<uses-permission android:name="android.permission.RECORD_AUDIO" />  
<uses-permission android:name="android.permission.INTERNET" />
```

And check for permission if it is granted to your application or not.

## Code Sample
In your Android code (can be either an activity or a service), create a `Config` object with the parameters which are set in ***IceCast stream source***  and pass it to the Live Audio.
```java
Config c = new Config();  
c.host("192.168.43.194");  
c.port(8000);  
c.username("joker");  
c.password("hackme");  
c.mount("/harleyquinn");  
c.sampleRate(16000);  
  
LiveAudio l = new LiveAudio(c);  
try {  
    l.start();  
} catch (Exception e) {  
    e.printStackTrace();  
}
```
# Demo
The video can be found on YouTube about how to start the stream server and config the Android client. [https://youtu.be/ujgRlYc9rMg](https://youtu.be/ujgRlYc9rMg)

[![Android Live Audio Library](https://img.youtube.com/vi/ujgRlYc9rMg/0.jpg)](https://www.youtube.com/watch?v=ujgRlYc9rMg)

# Donation
You may donate this project using my BitCoin address at:
```
BitCoin:

1F5uiEmdCLJX5KktWHE1wkc63feKJYMmxS
```
