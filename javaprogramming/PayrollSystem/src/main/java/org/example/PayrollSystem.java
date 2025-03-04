package org.example;

public class PayrollSystem {

    public static void main(String[] args) throws Exception{
        System.out.println("SYSTEM STARTED!!");
        SalariedEmployee salariedEmployee = new SalariedEmployee("Join", "Smith", "111-11-1111", 800);
        CommissionEmployee commissionEmployee = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, 0.06);
        BasePlusCommissionEmployee basePlusCommissionEmployee = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, 0.04, 300);

        System.out.println("Employees processed individually using static binding:\n");

        salariedEmployee.print();
        System.out.println();
        commissionEmployee.print();
        System.out.println();
        basePlusCommissionEmployee.print();
        System.out.println();
    }
}
