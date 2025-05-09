using System;
using System.Collections.Generic;

class Student
{
    public int ID { get; set; }
    public string Name { get; set; }
    public double GPA { get; set; }
}

class Program
{
    static Dictionary<int, Student> studentDict = new Dictionary<int, Student>();
    static Stack<Student> undoStack = new Stack<Shdtudent>();
    static Queue<string> registrationQueue = new Queue<string>();

    static void Main()
    {
        while (true)
        {
            Console.WriteLine("\n--- Student Management System ---");
            Console.WriteLine("1. Add Student");
            Console.WriteLine("2. View All Students");
            Console.WriteLine("3. Search Student by ID");
            Console.WriteLine("4. Delete Student");
            Console.WriteLine("5. Undo Last Add");
            Console.WriteLine("6. Register for Event");
            Console.WriteLine("7. Show Registration Queue");
            Console.WriteLine("0. Exit");
            Console.Write("Select an option: ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1": AddStudent(); break;
                case "2": ViewAllStudents(); break;
                case "3": SearchStudent(); break;
                case "4": DeleteStudent(); break;
                case "5": UndoLastAdd(); break;
                case "6": RegisterStudent(); break;
                case "7": ShowQueue(); break;
                case "0": return;
                default: Console.WriteLine("Invalid choice."); break;
            }
        }
    }

    static void AddStudent()
    {
        Console.Write("Enter Student ID: ");
        int id = int.Parse(Console.ReadLine());

        Console.Write("Enter Name: ");
        string name = Console.ReadLine();

        Console.Write("Enter GPA: ");
        double gpa = double.Parse(Console.ReadLine());

        var student = new Student { ID = id, Name = name, GPA = gpa };
        studentDict[id] = student;
        undoStack.Push(student);

        Console.WriteLine("Student added successfully.");
    }

    static void ViewAllStudents()
    {
        if (studentDict.Count == 0)
        {
            Console.WriteLine("No students found.");
            return;
        }

        Console.WriteLine("ID\tName\tGPA");
        foreach (var s in studentDict.Values)
        {
            Console.WriteLine($"{s.ID}\t{s.Name}\t{s.GPA}");
        }
    }

    static void SearchStudent()
    {
        Console.Write("Enter Student ID to search: ");
        int id = int.Parse(Console.ReadLine());

        if (studentDict.ContainsKey(id))
        {
            var s = studentDict[id];
            Console.WriteLine($"Name: {s.Name}, GPA: {s.GPA}");
        }
        else
        {
            Console.WriteLine("Student not found.");
        }
    }

    static void DeleteStudent()
    {
        Console.Write("Enter Student ID to delete: ");
        int id = int.Parse(Console.ReadLine());

        if (studentDict.Remove(id))
            Console.WriteLine("Student deleted.");
        else
            Console.WriteLine("Student not found.");
    }

    static void UndoLastAdd()
    {
        if (undoStack.Count > 0)
        {
            var last = undoStack.Pop();
            studentDict.Remove(last.ID);
            Console.WriteLine("Last student addition undone.");
        }
        else
        {
            Console.WriteLine("Nothing to undo.");
        }
    }

    static void RegisterStudent()
    {
        Console.Write("Enter student name to register: ");
        string name = Console.ReadLine();
        registrationQueue.Enqueue(name);
        Console.WriteLine("Student registered for the event.");
    }

    static void ShowQueue()
    {
        Console.WriteLine("Students in queue:");
        foreach (string name in registrationQueue)
            Console.WriteLine(name);
    }
}
