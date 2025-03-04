package org.example;

public class CommissionEmployee extends Employee {
    private double grossSales;
    private double commissionRate;

    public CommissionEmployee(String first, String last, String ssn, double sales, double rate) throws Exception{
        super(first, last, ssn);
        setGrossSales(sales);
        setCommissionRate(rate);
    }

    @Override()
    public double earning(){
        return getCommissionRate() * getGrossSales();
    }

    @Override()
    public void print () {
        System.out.print("Commission employee: ");
        super.print();
        System.out.println("Gross Sales: " + getGrossSales());
        System.out.println("Commission Rate: " + getCommissionRate());
    }

    public double getGrossSales() {
        return grossSales;
    }

    public void setGrossSales(double grossSales) throws Exception {
        if (grossSales >= 0.0) {
            this.grossSales = grossSales;
        }
        else {
            throw new Exception("Gross sales must be >= 0.0!!");
        }
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public void setCommissionRate(double commissionRate) {
        this.commissionRate = commissionRate;
    }
}
