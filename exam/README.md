# Крестики-нолики Рогожников 14121
## Классы:
# 1.Cell
### Ячейки, из которых состоит доска
### Поля:
#### a)char value
### Методы:
#### a) Конструктор Cell()
#### Задает при инициализации value = ' '
#### b) void SetValue()
#### c) char GetValue()
#### Проявление инкапсуляции
# 2.Board
### Поля:
#### a)Cell cells[20][20]
#### b)pair lastMove
### Методы:
#### a)Board()
#### Заполняет cells объектами типа Cell
#### b)void display()
#### Вывод доски для идущей игры
#### c)bool IsValidMove(int x, int y) const
#### Проверка типа данных, незанятости ячейки и значений x,y
#### d)pair<pair<int, int>, pair<int, int>> Connectivity(int x, int y, char player) const
#### Возвращает максимальную связность для проверки победы и другие значения для реализации алгоритма игры компьютера
#### e)bool isFull() const
#### Проверка для ничьей
#### f)pair<int, int> getLastMove() const
#### Последний ход на доске для реализации алгоритма компьютера
#### g)pair<int, int> Hint(const Board& board,char player, std::pair<int,int> step_enemy) const
#### Алгоритм для определения лучшего хода на основе последнего хода противника(не доработан(Закомментирован), версия для тестов всех остальных классов использует случайные возможные ходы)
# 4.ComputerPlayer
### Поля:
#### a)char player
#### X или O
### Методы:
#### a)ComputerPlayer(char player)
#### Конструктор инициализирующий player 
#### b)char GetPlayer()
#### c)pair<int, int> GetMove(const Board& board)
#### Ход компьютера рассчитывается при помощи Hint() из Board
### 3.Game
### Поля:
#### a)Board board
#### Инициализация игрового поля
#### b)vector <spair<int, int>> history
#### Массив для запоминания истории
### Методы:
#### a)void play();
#### Игра с компьютером
#### b)void GameDemonstration();
#### Демонстрация игрового процесса
#### c)void SaveHistory()
#### Сохранение истории в файл