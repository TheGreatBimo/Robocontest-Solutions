[Problem link](https://robocontest.uz/tasks/A0032)
#### Translation:
Video

Siroj wants to watch a movie on YouTube. The movie lasts T seconds, each second of the video has size A, and Siroj’s internet speed is B per second. Fortunately, B < A.

If Siroj starts playing the video immediately, it may pause intermittently. To watch the movie without interruptions, determine the minimum number of seconds he must wait after accessing the video before starting playback.

#### Solution:
We can check if time M is enough for us to watch the video.

If we wait M amount of time, M*B data is downloaded,
And the rest of the video is downloaded during playback.
So the downloaded data is M*B+B*T

if the downloaded data is larger than the size of the video (A*T) waiting M time is enough.

If waiting M time is enough, it can be proven that M+1 time is also enough
If waiting M time is not enough, it can be proven that M-1 time is also not enough

Thus the result is monotonic, and in order to find the minimum time enough we can use binary search.