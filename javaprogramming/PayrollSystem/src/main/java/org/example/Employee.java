package org.example;
import java.lang.*;

public class Employee {
    private String fisrtName;
    private String lastName;
    private String socialSecurityNumber;

    public Employee(String first, String last, String ssn){
        this.fisrtName = first;
        this.lastName = last;
        this.socialSecurityNumber= last;
    };

    public double earning(){
        return 0.0;
    };

    public void print() {
        System.out.println(fisrtName + ' ' + lastName);
        System.out.println("Social Security Number: " + socialSecurityNumber);
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFisrtName() {
        return fisrtName;
    }

    public void setFisrtName(String fisrtName) {
        this.fisrtName = fisrtName;
    }

    public String getSocialSecurityNumber() {
        return socialSecurityNumber;
    }

    public void setSocialSecurityNumber(String socialSecurityNumber) {
        this.socialSecurityNumber = socialSecurityNumber;
    }
}
