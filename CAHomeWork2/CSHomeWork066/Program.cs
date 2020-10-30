using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork066
{
    enum TMyCardSuit
    {
        Hearts,// – червы
        Diamonds,// – бубны
        Clubs,// – трефы
        Spades// – пики
    }

    enum TMyCardValue // старшинство карт принимаем по числу очков (возможно другую расстановку старшинства)
    {
        Six = 6,// - шесть	
        Seven = 7,// - семь	
        Eight = 8,// - восемь	
        Nine = 9,// - девять
        Ten = 10,// - 10
        Jack = 2,// – валет
        Queen = 3,// – дама
        King = 4,// – король
        Ace = 11// – туз
    }

    class TMyCard
    {
        public TMyCard(TMyCardSuit Suit = TMyCardSuit.Clubs, TMyCardValue Value = TMyCardValue.Six)
        {
            this.Suit = Suit;
            this.Value = Value;
        }
        public TMyCardSuit Suit { get; set; }
        public TMyCardValue Value { get; set; }
        public void Show(int x = 0, int y = 0)
        {
            Console.Write(ToStr());
        }

        public string ToStr()
        {
            char S;
            string V;
            switch (Suit)
            {
                case TMyCardSuit.Hearts:
                    S = 'H';
                    break;
                case TMyCardSuit.Diamonds:
                    S = 'D';
                    break;
                case TMyCardSuit.Clubs:
                    S = 'C';
                    break;
                case TMyCardSuit.Spades:
                    S = 'S';
                    break;
                default:
                    S = '.';
                    break;
            }

            switch (Value)
            {
                case TMyCardValue.Jack:
                    V = "J";
                    break;
                case TMyCardValue.Queen:
                    V = "Q";
                    break;
                case TMyCardValue.King:
                    V = "K";
                    break;
                case TMyCardValue.Ace:
                    V = "A";
                    break;
                case TMyCardValue.Ten:
                    V = "10";
                    break;
                case TMyCardValue.Nine:
                    V = "9";
                    break;
                case TMyCardValue.Eight:
                    V = "8";
                    break;
                case TMyCardValue.Seven:
                    V = "7";
                    break;
                case TMyCardValue.Six:
                    V = "6";
                    break;
                default:
                    V = ".";
                    break;
            }
            return V + S;
        }
    }

    class TMyPlayer
    {
        public TMyPlayer(string Name)
        {
            Cards = new Stack<TMyCard>();
            this.Name = Name;
        }
        public Stack<TMyCard> Cards;
        public string Name { get; set; }

        public void Show(int x = 0, int y = 0)
        {
            Console.WriteLine("Player " + this.Name + ":");
            foreach (var Card in Cards)
            {
                Card.Show(x, y);
                Console.Write(" ");
            }
        }

        public void Push(TMyCard Card)
        {
            Cards.Push(Card);
        }

        public TMyCard Pop()
        {
            return Cards.Pop();
        }

        public bool Active()
        {
            return Convert.ToBoolean(Cards.Count());
        }
    }

    class TMyGame
    {
        public TMyGame()
        {
            Players = new Stack<TMyPlayer>();
            Deck = new Stack<TMyCard>();

            for (int i = 0; i <= (int)TMyCardSuit.Spades; i++)
            {
                for (int k = 0; k < Enum.GetNames(typeof(TMyCardValue)).Length; k++) 
                {
                    Deck.Push(new TMyCard((TMyCardSuit)i,
                        (TMyCardValue)Enum.GetValues(typeof(TMyCardValue)).GetValue(k)));
                }
            }

            ShuffleCards();
        }
        public Stack<TMyPlayer> Players;
        private Stack<TMyCard> Deck;

        public void Show(int x = 0, int y = 0)
        {
            int i = 1;
            Console.WriteLine("Deck: ");
            foreach (var Card in Deck)
            {
                Console.Write(Card.ToStr() + " ");
                i++;
            }
            Console.WriteLine();

            foreach (var Player in Players)
            {
                Player.Show();
                Console.WriteLine();
            }

            Console.WriteLine("\n");
        }

        public void Push(TMyPlayer Player)
        {
            Players.Push(Player);
        }

        public TMyPlayer Pop()
        {
            return Players.Pop();
        }
       
        // раздаем карты игрокам
        private void PlayersInit(int Count)
        {            
            for (int i = 0; i < Count; i++)
            {
                Players.Push(new TMyPlayer("Player " + (i+1)));
            }

            while (Deck.Count() > 0)
            {
                foreach (var Player in Players)
                {
                    if (Deck.Count() > 0)
                        Player.Push(Deck.Pop());
                    else break;
                }
            }
        }

        // Собираем карты от игроков
        private void PlayersDispose()
        {
            foreach (var Player in Players)
            {
                while (Player.Cards.Count() > 0)
                {
                    Deck.Push(Player.Pop());
                }
            }
            Players.Clear();
        }

        //тасуем карты
        public void ShuffleCards()
        {
            Random rnd = new Random();            
            PlayersInit(rnd.Next(2, 10));
            PlayersDispose();
            PlayersInit(rnd.Next(2, 10));
            PlayersDispose();
            PlayersInit(rnd.Next(2, 10));
            PlayersDispose();
        }

        // игровой алгоритм
        private void GameLogic()
        {
            Stack<TMyCard> tmpHeap = new Stack<TMyCard>();
            TMyPlayer Winner = null;
            TMyCard tmpCard = null;
            int Move = 1;

            while (true)
            {
                Console.WriteLine("Move " + Move);
                foreach (var Player in Players)
                {
                    if (Player.Cards.Count() > 0)
                    {
                        if (tmpCard == null)
                        {
                            tmpCard = Player.Cards.Peek();
                            Winner = Player;                           
                        }
                        else if (tmpCard.Value < Player.Cards.Peek().Value)
                        {
                            tmpCard = Player.Cards.Peek();
                            Winner = Player;                           
                        }
                        Deck.Push(Player.Cards.Pop());
                    }
                }
                Show();
                if (Deck.Count() > 1)
                {
                    while (Deck.Count() > 0)
                    {
                        Winner.Push(Deck.Pop());
                    }
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine("Player take cards on this move: " + Winner.Name + "\n");
                    Console.ForegroundColor = ConsoleColor.White;
                }
                else
                {
                    while (Deck.Count() > 0)
                    {
                        Winner.Push(Deck.Pop());
                    }
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine("Player take cards on this move: " + Winner.Name + "\n");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("Player WIN: " + Winner.Name);
                    Winner.Show();
                    Console.WriteLine("\n");
                    break;
                }
                Move++;
                Winner = null;
                tmpCard = null;
            }
        }

        public void Run()
        {
            bool play = true;
            int Operation;
            while (play)
            {
                Console.Write("Enter players count (0 or negative to Exit): ");
                Operation = Convert.ToInt32(Console.ReadLine());
                if ((Operation == 0) || (Operation < 0))
                {
                    play = false;
                    break;
                }
                Show(); //out Deck;

                Console.WriteLine("Players init...");
                PlayersInit(Operation);
                Console.WriteLine();

                Show(); //out Deck;
                Console.WriteLine();

                GameLogic();

                Console.WriteLine("Players Dispose...");
                PlayersDispose();
                Console.Write("Game is over (press enter to continue)...");
                Console.ReadLine();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            /* Задание 1. Программа «Карточная игра!»
           Создать модель карточной игры.
           Требования:
           1. Класс Game формирует и обеспечивает:
           1.1.1. Список игроков (минимум 2);
           1.1.2. Колоду карт (36 карт);
           1.1.3. Перетасовку карт (случайным образом);
           1.1.4. Раздачу карт игрокам (равными частями каждому игроку);
           1.1.5. Игровой процесс. Принцип: Игроки кладут по одной карте. У кого карта больше, то тот игрок забирает все карты и кладет их в конец своей колоды. Упрощение: при совпадении карт забирает первый игрок, шестерка не забирает туза. Выигрывает игрок, который забрал все карты.
           2. Класс Player (набор имеющихся карт, вывод имеющихся карт).
           3. Класс Karta (масть и тип карты (6-10, валет, дама, король, туз). */

            TMyGame Game = new TMyGame();

            Game.Run();

        }
    }
}
