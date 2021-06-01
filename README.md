# 2021_wk_oop_P2

This is the homework of Weng Kai’s OOP, Zhejiang University.

The description is as follows.

---

Adventure is a CLI game. The player has to explore in the castle with many levels and a lot of rooms. The task of the player is to find a room where the princess is prinsoned and take her leave the castle. There are many types of rooms, and each type of room has different types of exits. Note that there's a monster in one of the rooms, which the exact location is not able to be aware. But once the player meets a monster, the game is over.

When the game starts, the player is at the lobby of the castle. Then the program shows information about the lobby's name of the room, how many exits are there, and names of all exits (e.g.: "east", "south", "up"), like:

> ```
> Welcome to the lobby. There are 3 exits as: east, west and up.
> 
> Enter your command:
> ```

The player then can input "go" followed by the name of one exit to enter the room connected with that door, like:

> ```
> go east     
> ```

The player goes into the room to the east. The program shows the information about that room, like what happened in the lobby just now. And the player may input command to choose another room. Once the player enters a room with a monster, the program shows a message and game over. Once the player enters the room of princess, the program shows a message about the princess, and the process is going to leave with the player. The player then has to find their way out the castle. The only way to leave the castle is via the lobby.

All printed messages and user input are in English to simplify the code.

## Requirement

- At least three different kinds of room;
- At least five rooms;
- The room with monster or princess is randomly set.

# 游戏说明

1. **编译**：如果装有gcc可以直接在终端利用makefile进行编译。Windows系统请用现在的makefile，输入命令`mingw32-make`；Linux/MacOS请用UnixMakefile（记得先改名）然后直接`make`
2. **帮助**：进入游戏后，输入`help`可以得到帮助；
3. **移动**：`go east/west/up/down`，只能向给定方向移动
4. **彩蛋**：输入特定命令可以实现意想不到的效果（
   * 提示：
     * 一个是脏话
     * 一个是著名的梗
     * 在给人物命名时可以实现意想不到的效果
   * 具体指令见`main.cpp`的`getCommand()`函数（嘿嘿嘿就不直接告诉你（））
5. [github链接](https://github.com/ZhaoHongjue/2021_wk_oop_P2)
6. 我不是CS专业的学生，实现不好的地方还请多多指教

