package org.example;
import java.lang.*;

public class SalariedEmployee extends Employee {
    private double weeklySalary;

    public SalariedEmployee(String first, String last, String ssn, double salary) throws Exception{
        super(first, last, ssn);
        setWeeklySalary(salary);
    }

    public double getWeeklySalary() {
        return weeklySalary;
    }

    public void setWeeklySalary(double weeklySalary) throws Exception {
        if (weeklySalary >= 0.0){

            this.weeklySalary = weeklySalary;
        }
        else{
            throw new Exception("Weeky Salary must be >= 0.0");
        }
    }

    @Override()
    public void print () {
        System.out.print("Salaried employee: ");
        super.print();
        System.out.println("Weekly salary: " + getWeeklySalary());
    }
}
