// Fast Forwarding
// Mr. Anderson frequently rents video tapes of his favorite classic films. Watching the films so many times, he has learned the precise start times of his favorite scenes in all such films. He now wants to find how to wind the tape to watch his favorite scene as quickly as possible on his video player.

// When the [play] button is pressed, the film starts at the normal playback speed. The video player has two buttons to control the playback speed: The [3x] button triples the speed, while the [1/3x] button reduces the speed to one third. These speed control buttons, however, do not take effect on the instance they are pressed. Exactly one second after playback starts and every second thereafter, the states of these speed control buttons are checked. If the [3x] button is pressed on the timing of the check, the playback speed becomes three times the current speed. If the [1/3x] button is pressed, the playback speed becomes one third of the current speed, unless it is already the normal speed.

// For instance, assume that his favorite scene starts at 19 seconds from the start of the film. When the [3x] button is on at one second and at two seconds after the playback starts, and the [1/3x] button is on at three seconds and at five seconds after the start, the desired scene can be watched in the normal speed five seconds after starting the playback, as depicted in the following chart.


// Your task is to compute the shortest possible time period after the playback starts until the desired scene starts. The playback of the scene, of course, should be in the normal speed.

// Input
// The input consists of a single test case of the following format.

// [Math Processing Error]
// The given single integer [Math Processing Error] ([Math Processing Error]) is the start time of the target scene.

// Output
// Print an integer that is the minimum possible time in seconds before he can start watching the target scene in the normal speed.

