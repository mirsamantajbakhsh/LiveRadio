package ir.mstajbakhsh.liveaudio;

public class LiveAudio {

    private Config _config;
    private static Encoder e;

    public LiveAudio(Config config) {
        _config = config;
    }

    public void start() throws Exception {
        if (e != null) {
            if (e.isRecording()) {
                throw new Exception("Encoder is still recording. Please stop it first before starting again.");
            }
        } else {
            e = new Encoder(_config);
        }
        e.start();
    }

    public void stop() {
        if (e != null) {
            e.stop();
        }
    }

    public boolean isStreaming() {
        try {
            return e.isRecording();
        } catch (Exception ex) {
            return false;
        }
    }

}
