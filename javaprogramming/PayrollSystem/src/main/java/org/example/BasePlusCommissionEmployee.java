package org.example;
import java.lang.Exception;

public class BasePlusCommissionEmployee extends CommissionEmployee {
    private double baseSalary;

    public BasePlusCommissionEmployee(String first, String last, String ssn, double sales, double rate, double salary) throws Exception{
        super(first, last, ssn, sales, rate);
        setBaseSalary(salary);
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) throws Exception{
        if (baseSalary >= 0.0) {
            this.baseSalary = baseSalary;
        }
        else {
            throw new Exception("Base Salary must be >= 0.0!");
        }
    }

    @Override
    public double earning() {
        return super.earning() + getBaseSalary();
    }

    @Override
    public void print() {
        System.out.println("Base-salaried");
        super.print();
        System.out.println("Base salary: " + getBaseSalary());
    }
}
