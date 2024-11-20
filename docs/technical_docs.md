# Tổ chức thư mục dự án
Để thuận tiện cho việc quản lý, bảo trì và phát triển, dự án được tổ chức với cấu trúc thư mục như sau: 


```
SnakeGame/
├── src/                     # Chứa mã nguồn chính của trò chơi
│   ├── main.cpp             # Tệp main - Điểm bắt đầu của trò chơi
│   ├── Game.h / Game.cpp    # Lớp Game: Quản lý vòng lặp trò chơi, xử lý đầu vào, cập nhật trạng thái
│   ├── Snake.h / Snake.cpp  # Lớp Snake: Điều khiển rắn di chuyển, kiểm tra va chạm, tăng chiều dài
│   ├── Food.h / Food.cpp    # Lớp Food: Tạo thức ăn ngẫu nhiên, kiểm tra vị trí
│   ├── UI.h / UI.cpp        # Lớp UI: Hiển thị điểm số và thông báo
├── assets/                  # Lưu trữ tài nguyên trò chơi
│   └── .gitkeep             # Tệp giữ chỗ để đảm bảo thư mục được lưu trong Git
├── docs/                    # Lưu trữ tài liệu dự án
│   ├── user_guide.md        # Hướng dẫn chi tiết cách chơi trò chơi
│   ├── technical_docs.md    # Tài liệu kỹ thuật chi tiết về các lớp và thuật toán trong trò chơi
├── build/                   # Thư mục chứa các tệp biên dịch và tệp tạm thời
│   └── .gitkeep
├── README.md                # Tệp README, mô tả dự án và hướng dẫn sử dụng
├── .gitignore               # Tệp .gitignore để loại trừ các tệp không cần thiết khỏi Git
├── Dockerfile               # Cấu hình Docker để chạy game
└── Makefile                 # Cấu hình Makefile để biên dịch

```

# Chức năng chính của trò chơi
• **Di chuyển rắn (Snake Movement):** Rắn được điều khiển bởi các phím mũi tên (Up, Down,
Left, Right).

• **Sinh thức ăn ngẫu nhiên (Food Spawning):** Thức ăn được sinh ngẫu nhiên tại các vị trí
trên màn hình.

• **Kết thúc trò chơi (Game Over):** Trò chơi kết thúc khi đầu rắn cắn vào thân rắn.

# Cấu trúc chính của chương trình

**Class Game**: Chịu trách nhiệm quản lý vòng lặp chính của trò chơi và kết nối các thành phần như rắn, thức ăn và giao diện người dùng (UI). Các chức năng chính bao gồm:

• `run()`: Thực hiện vòng lặp chính của trò chơi, liên tục cập nhật trạng thái và hiển thị.

• `render()`: Hiển thị các đối tượng trò chơi (rắn, thức ăn, điểm số, v.v.) lên màn hình.

• `update()`: Cập nhật trạng thái trò chơi, kiểm tra logic va chạm và sinh thức ăn mới.


**Class Snake**: Quản lý trạng thái và hành vi của rắn trong trò chơi. Cụ thể:

• `move()`: Di chuyển đầu rắn dựa trên hướng hiện tại.

• `grow()`: Thêm một đơn vị vào thân rắn.

• `checkCollision()`: Kiểm tra va chạm giữa đầu rắn với thân hoặc tường.


**Class Food**: Chịu trách nhiệm sinh ra thức ăn và quản lý vị trí của nó. Các chức năng chính:

• `spawn()`: Tạo ra thức ăn tại một vị trí ngẫu nhiên trên bản đồ.

• `draw()`: Vẽ thức ăn lên màn hình.


**Class UI**: Hiển thị thông tin giao diện trò chơi, bao gồm điểm số và thông báo kết thúc. Các chức năng chính:

• `displayScore()`: Hiển thị điểm số hiện tại của người chơi trên màn hình.

• `gameOverMessage()`: Hiển thị thông báo khi trò chơi kết thúc.

# Cấu trúc dữ liệu và giải thuật chính

![Snake Game Class Diagram](assets\diagrampng.png)

| **Thành phần**          | **Kiểu dữ liệu**        | **Giải thích**                                                                                                                                  |
|--------------------------|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| **SnakeBody (Thân Rắn)** | `std::vector`          | `std::vector` được chọn vì khả năng quản lý kích thước động, truy cập nhanh vào các đoạn thân và tính tuần tự trong bộ nhớ. Mỗi đoạn thân rắn là một phần tử trong vector, với đầu rắn ở phần tử đầu tiên. Khi rắn di chuyển, các đoạn thân được cập nhật theo vị trí của đoạn liền trước. Khi rắn ăn thức ăn, một đoạn thân mới được thêm vào cuối vector. |
| **Food (Thức ăn)**       | `sf::RectangleShape`   | `sf::RectangleShape` được chọn để biểu diễn thức ăn vì khả năng hiển thị trực tiếp hình chữ nhật trên cửa sổ trò chơi và dễ dàng quản lý các thuộc tính như kích thước, màu sắc và vị trí. Kích thước cố định của thức ăn (10x10 pixel) khớp với các đoạn thân rắn. Vị trí thức ăn được sinh ngẫu nhiên trên lưới bằng cách sử dụng tọa độ phù hợp và đảm bảo không trùng lặp với thân rắn. |
| **Score (Điểm số)**      | `int`                  | `int` được sử dụng để lưu trữ điểm số của người chơi. Mỗi khi rắn ăn thức ăn, điểm số tăng lên một giá trị cố định, kiểu dữ liệu số nguyên giúp đảm bảo tính hiệu suất cao và đủ đơn giản để quản lý điểm số trong trò chơi. |
| **Direction (Hướng di chuyển)** | `sf::Vector2f`       | `sf::Vector2f` được sử dụng để lưu hướng di chuyển của rắn dưới dạng vector hai chiều (x, y). Mỗi giá trị vector tương ứng với một hướng di chuyển cụ thể (ví dụ: (1, 0) là sang phải, (0, −1) là lên). Hướng này được nhân với khoảng cách di chuyển để tính toán vị trí mới của đầu rắn, đồng thời đảm bảo rắn không di chuyển ngược lại hướng hiện tại. |

---

### 1. Di chuyển rắn (Snake Movement)
• **Mô tả**: Thuật toán di chuyển rắn được thiết kế để đảm bảo rằng mỗi đoạn thân rắn di chuyển chính xác theo vị trí đoạn thân phía trước.  Khi đầu rắn vượt qua ranh giới màn hình, nó sẽ quay lại phía đối diện (kiểu *wrap-around*).

```plaintext
Algorithm 1: Snake Movement Algorithm with Screen Wrapping
Input: Snake body as a list of segments, direction vector, segment size, window size
Output: Updated position of the snake's segments and wrapped position if it moves out of bounds.

function MoveSnake(windowSize) # Move the snake’s body based on direction and wrap around if it reaches the edge
    1. Move the body segments (excluding the head):
    for i = body.size() - 1 to 1 do
        body[i].position = body[i - 1].position
    end for

    2. Move the head in the current direction:
    body[0].position = body[0].position + direction * segmentSize

    3. Wrap the head position if it goes out of bounds:
    headPos = body[0].position
    if headPos.x < 0 then
        headPos.x = windowSize.width - segmentSize
    else if headPos.x >= windowSize.width then
        headPos.x = 0
    end if
    if headPos.y < 0 then
        headPos.y = windowSize.height - segmentSize
    else if headPos.y >= windowSize.height then
        headPos.y = 0
    end if
    body[0].position = headPos
end function
```

• **Time Complexity**: $O(n)$, với $n$ là số đoạn thân, cụ thể. Thao tác cập nhật lại thân rắn tốn độ phức tạp $O(n)$ do phải duyệt qua toàn bộ vector và cập nhật. Thao tác "xuyên biên" tốn $O(1)$ để kiểm tra và cập nhật vị trí head.

### 2. Phát hiện va chạm (Collision Detection)
• **Mô tả**: Thuật toán phát hiện va chạm được thiết kế để kiểm tra xem đầu rắn có chạm vào bất kỳ đoạn thân nào của chính nó hay không. Điều này giúp xác định khi nào trò chơi kết thúc. Dưới đây là mã giả mô tả chi tiết thuật toán này:

```plaintext
Algorithm 2: Collision Detection Algorithm for Snake Body
Input: Snake body as a list of segments, each segment represented as coordinates (x, y)
Output: Boolean indicating whether a collision with the snake’s own body has occurred.

function CheckCollision # Check if the snake’s head collides with any other part of its body
    head = body[0].position  # Get the position of the head segment
    for each segment in body[1:] do
        if segment.position == head then
            return TRUE  # Collision with snake's body
        end if
    end for
    return FALSE  # No collision detected
end function
```
• **Time Complexity**: $O(n)$, với $n$ là số đoạn thân rắn do chúng ta duyệt vào phần thân rắn để so sánh với head.

### 3. Sinh thức ăn ngẫu nhiên (Food Spawning)
• **Mô tả**: Thuật toán sinh thức ăn được thiết kế để đặt thức ăn tại một vị trí ngẫu nhiên trên bản đồ. Dưới đây là mã giả mô tả chi tiết thuật toán này:

```plaintext
Algorithm 3: Random Food Spawn Algorithm Aligned with Grid
Input: Window size (width, height)
Output: New random position (x, y) for the food, aligned with the grid

function SpawnFood(windowSize) # Generate random position for food within the window boundaries
1. Generate random coordinates within the window size:
   x = random integer between [0, windowSize.width)
   y = random integer between [0, windowSize.height)

2. Align the position with the grid:
   shape.position = (x, y)  # Set the position of the food shape
end function
```
• **Time Complexity**: $O(1)$ do chỉ tốn chi phí ở thao tác random và tính toán đơn giản.
