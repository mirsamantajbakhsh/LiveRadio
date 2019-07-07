package ir.mstajbakhsh.liveaudio;

import java.io.IOException;

public class ShoutOutputStream {

    static {
        try {
            System.loadLibrary("ogg");
            System.loadLibrary("vorbis");
            System.loadLibrary("vorbis-jni");
            System.loadLibrary("shout");
            System.loadLibrary("shout-jni");
        } catch (Exception ex) {
            //Do nothing
        }
    }

    public ShoutOutputStream() {
    }

    /**
     * Init shout client environment and connect
     * @param url
     * @param port
     * @param mount
     * @param user
     * @param password
     * @throws IOException
     */
    public void init(String url, int port, String mount, String user, String password) throws Exception {
        boolean ready = jniInit(url, port, mount, user, password) > 0;
        if (!ready) {
            throw new Exception("Stream is not initialized");
        }
    }

    /**
     * Pass mp3 data bytes to shout send buffer
     * @param buffer
     * @param count
     * @throws IOException
     */
    public void write(byte[] buffer, int count) throws IOException {
        jniSend(buffer, count);
    }

    /**
     * Close shout connection and reset environment
     * @throws IOException
     */
    public void close() throws IOException {
        jniClose();
    }

    private native int jniInit(String url, int port, String mount, String user, String password);
    private native int jniSend(byte[] buffer, int length);
    private native int jniClose();
}

