# video-player-cpp
Simple video player in Cpp.

That's it for the code! Now, if you're on Linux or a similar platform, you'll run:

gcc -o main main.cpp -lavutil -lavformat -lavcodec -lz -lavutil -lm

gcc seu_programa.cpp -o seu_programa -lavformat -lavcodec -lavutil -lswresample

gcc -o codec codec.cpp -lavformat -lavcodec -lavutil -lswresample

If you have an older version of ffmpeg, you may need to drop -lavutil:
gcc -o main main.cpp -lavformat -lavcodec -lz -lm
