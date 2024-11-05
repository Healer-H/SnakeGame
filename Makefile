# Kiểm tra hệ điều hành
ifeq ($(OS),Windows_NT)
    CXX = g++.exe        # Trình biên dịch cho Windows (MinGW)
    RM = del             # Lệnh xóa file trên Windows
    EXECUTABLE = snake_game.exe
else
    CXX = g++            # Trình biên dịch cho Linux/Mac
    RM = rm -f           # Lệnh xóa file trên Linux/Mac
    EXECUTABLE = snake_game
endif

# Cờ biên dịch
CXXFLAGS = -std=c++11 -I/usr/local/include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Thư mục mã nguồn và thư mục build
SRC_DIR = src
OBJ_DIR = build

# Danh sách các file mã nguồn
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Quy tắc biên dịch
$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXECUTABLE) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Tạo thư mục build nếu chưa có
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Quy tắc dọn dẹp
clean:
	$(RM) $(OBJ_DIR)/*.o $(EXECUTABLE)
