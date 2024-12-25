using System;
using System.IO;

public class PaymentInvoice
{
    public double DailyPayment { get; set; }
    public int NumberOfDays { get; set; }
    public double PenaltyPerDay { get; set; }
    public int NumberOfLateDays { get; set; }

    public double AmountDueWithoutPenalty => DailyPayment * NumberOfDays;
    public double Penalty => PenaltyPerDay * NumberOfLateDays;
    public double TotalAmountDue => AmountDueWithoutPenalty + Penalty;
}

class Program
{
    static void Main()
    {
        PaymentInvoice invoice = new PaymentInvoice
        {
            DailyPayment = 100,
            NumberOfDays = 20,
            PenaltyPerDay = 5,
            NumberOfLateDays = 3
        };

        using (StreamWriter writer = new StreamWriter(@"...\Log.txt")) // File path
        {
            {
                writer.WriteLine($"Daily Payment: {invoice.DailyPayment}");
                writer.WriteLine($"Number of Days: {invoice.NumberOfDays}");
                writer.WriteLine($"Penalty per Day: {invoice.PenaltyPerDay}");
                writer.WriteLine($"Number of Late Days: {invoice.NumberOfLateDays}");
                writer.WriteLine($"Amount Due without Penalty: {invoice.AmountDueWithoutPenalty}");
                writer.WriteLine($"Penalty: {invoice.Penalty}");
                writer.WriteLine($"Total Amount Due: {invoice.TotalAmountDue}");
        }

        using (StreamReader reader = new StreamReader(@"...\Log.txt")) // File path
        {
            string line;
            while ((line = reader.ReadLine()) != null)
            {
                Console.WriteLine(line);
            }
        }
    }
}
