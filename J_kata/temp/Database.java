import java.*;
import java.util.*;

public class Database
{
	public static void main(String[] args)
	{
		double temp = 0.0;
		double hum = 0.0;
		Database a = new Database();
		a.arrayMakerMethod();
		String process = a.temp1Method(temp);
		System.out.println("Thermometer #1 is " + process);
		String process1 = a.temp2Method(temp);
		System.out.println("Thermometer #2 is " + process1);
		String process2 = a.hum1Method(hum);
		System.out.println("Humidity Sensor #1 " + process2);
		String process3 = a.hum2Method(hum);
		System.out.println("Humidity Sensor #2 " + process3);
	}

    // instance variables
    double inputTemp;
    double inputHum;
    double [] inputTemp1;
    double [] inputTemp2;
    double [] inputHum1;
    double [] inputHum2;
    int numTemp1;
    int numTemp2;
    int numHum1;
    int numHum2;
    String temp;
    String hum;
    String num1;
    String num2;
    String num3;
    String num4;
    String temp1;
    String temp2;
    String hum1;
    String hum2;

    /**
     * Constructor for objects of class Database
     */
    public Database()
    {
        // initialise instance variables
        System.out.println("Enter ambient temperature of the room: ");
        Scanner scanner = new Scanner(System.in);
        temp = scanner.nextLine();
        System.out.println("The temperature is " + temp);
        
        System.out.println("Enter ambient humidity of the room: ");
        hum = scanner.nextLine();
        System.out.println("The humidity is " + hum);
        
        System.out.println("Enter number of readings for thermometer number 1: ");
        num1 = scanner.nextLine();
        System.out.println("The number of readings is " + num1);
        
        System.out.println("Enter all temperature readings for thermometer number 1 separated by a space: ");
        temp1 = scanner.nextLine();
        System.out.println("The readings are " + temp1);
        
        System.out.println("Enter number of readings for thermometer number 2: ");
        num2 = scanner.nextLine();
        System.out.println("The number of readings is " + num2);
        
        System.out.println("Enter all temperature readings for thermometer number 2 separated by a space: ");
        temp2 = scanner.nextLine();
        System.out.println("The readings are " + temp2);
        
        System.out.println("Enter number of readings for humidity sensor number 1: ");
        num3 = scanner.nextLine();
        System.out.println("The number of readings is " + num3);
        
        System.out.println("Enter all readings for humidity sensor number 1 separated by a space: ");
        hum1 = scanner.nextLine();
        System.out.println("The readings are " + hum1);
        
        System.out.println("Enter number of readings for humidity sensor number 2: ");
        num4 = scanner.nextLine();
        System.out.println("The number of readings is " + num4);
        
        System.out.println("Enter all readings for humidity sensor number 2 separated by a space: ");
        hum2 = scanner.nextLine();
        System.out.println("The readings are " + hum2);

    }

    /**
     * Used to capture all data points and set them up for processing
     */
    public void arrayMakerMethod()
    {
        //gets the values from the strings
        for(int i = 0; i<temp.length(); i++)
        {
            String Temporary = temp.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                inputTemp += .1;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("2"))
            {
                inputTemp += .2;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("3"))
            {
                inputTemp += .3;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("4"))
            {
                inputTemp += .4;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("5"))
            {
                inputTemp += .5;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("6"))
            {
                inputTemp += .6;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("7"))
            {
                inputTemp += .7;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("8"))
            {
                inputTemp += .8;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("9"))
            {
                inputTemp += .9;
                inputTemp = inputTemp*10;
            }
            else if(Temporary.equals("0"))
            {
                inputTemp += 0;
                inputTemp = inputTemp*10;
            }
        }
        for(int i = 0; i<hum.length(); i++)
        {
            String Temporary = hum.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                inputHum += .1;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("2"))
            {
                inputHum += .2;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("3"))
            {
                inputHum += .3;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("4"))
            {
                inputHum += .4;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("5"))
            {
                inputHum += .5;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("6"))
            {
                inputHum += .6;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("7"))
            {
                inputHum += .7;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("8"))
            {
                inputHum += .8;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("9"))
            {
                inputHum += .9;
                inputHum = inputHum*10;
            }
            else if(Temporary.equals("0"))
            {
                inputHum += 0;
                inputHum = inputHum*10;
            }
        }
        for(int i = 0; i<num1.length(); i++)
        {
            String Temporary = num1.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                numTemp1 += .1;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("2"))
            {
                numTemp1 += .2;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("3"))
            {
                numTemp1 += .3;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("4"))
            {
                numTemp1 += .4;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("5"))
            {
                numTemp1 += .5;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("6"))
            {
                numTemp1 += .6;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("7"))
            {
                numTemp1 += .7;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("8"))
            {
                numTemp1 += .8;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("9"))
            {
                numTemp1 += .9;
                numTemp1 = numTemp1*10;
            }
            else if(Temporary.equals("0"))
            {
                numTemp1 += 0;
                numTemp1 = numTemp1*10;
            }
        }
        for(int i = 0; i<num2.length(); i++)
        {
            String Temporary = num2.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                numTemp2 += .1;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("2"))
            {
                numTemp2 += .2;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("3"))
            {
                numTemp2 += .3;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("4"))
            {
                numTemp2 += .4;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("5"))
            {
                numTemp2 += .5;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("6"))
            {
                numTemp2 += .6;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("7"))
            {
                numTemp2 += .7;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("8"))
            {
                numTemp2 += .8;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("9"))
            {
                numTemp2 += .9;
                numTemp2 = numTemp2*10;
            }
            else if(Temporary.equals("0"))
            {
                numTemp2 += 0;
                numTemp2 = numTemp2*10;
            }
        }
        for(int i = 0; i<num3.length(); i++)
        {
            String Temporary = num3.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                numHum1 += .1;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("2"))
            {
                numHum1 += .2;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("3"))
            {
                numHum1 += .3;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("4"))
            {
                numHum1 += .4;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("5"))
            {
                numHum1 += .5;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("6"))
            {
                numHum1 += .6;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("7"))
            {
                numHum1 += .7;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("8"))
            {
                numHum1 += .8;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("9"))
            {
                numHum1 += .9;
                numHum1 = numHum1*10;
            }
            else if(Temporary.equals("0"))
            {
                numHum1 += 0;
                numHum1 = numHum1*10;
            }
        }
        for(int i = 0; i<num4.length(); i++)
        {
            String Temporary = num4.substring(i,i+1);
            if(Temporary.equals("1"))
            {
                numHum2 += .1;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("2"))
            {
                numHum2 += .2;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("3"))
            {
                numHum2 += .3;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("4"))
            {
                numHum2 += .4;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("5"))
            {
                numHum2 += .5;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("6"))
            {
                numHum2 += .6;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("7"))
            {
                numHum2 += .7;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("8"))
            {
                numHum2 += .8;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("9"))
            {
                numHum2 += .9;
                numHum2 = numHum2*10;
            }
            else if(Temporary.equals("0"))
            {
                numHum2 += 0;
                numHum2 = numHum2*10;
            }
        }
        for(int i = 0; i<temp1.length(); i++)
        {
            for(int j = 0; j<numTemp1; j += 0)
            {
                String Temporary = temp1.substring(i,i+1);
                if(Temporary.equals("1"))
                {
                    inputTemp1[j] += .1;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("2"))
                {
                    inputTemp1[j] += .2;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("3"))
                {
                    inputTemp1[j] += .3;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("4"))
                {
                    inputTemp1[j] += .4;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("5"))
                {
                    inputTemp1[j] += .5;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("6"))
                {
                    inputTemp1[j] += .6;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("7"))
                {
                    inputTemp1[j] += .7;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("8"))
                {
                    inputTemp1[j] += .8;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("9"))
                {
                    inputTemp1[j] += .9;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals("0"))
                {
                    inputTemp1[j] += 0;
                    inputTemp1[j] = inputTemp1[j]*10;
                }
                else if(Temporary.equals(" "))
                {
                    j++;
                }
                System.out.println(j);
            }
        }
        for(int j = 0; j<numTemp2; j+=0)
        {
            for(int i = 0; i<temp2.length(); i++)
            {
                String Temporary = temp2.substring(i,i+1);
                if(Temporary.equals("1"))
                {
                    inputTemp2[j] += .1;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("2"))
                {
                    inputTemp2[j] += .2;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("3"))
                {
                    inputTemp2[j] += .3;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("4"))
                {
                    inputTemp2[j] += .4;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("5"))
                {
                    inputTemp2[j] += .5;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("6"))
                {
                    inputTemp2[j] += .6;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("7"))
                {
                    inputTemp2[j] += .7;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("8"))
                {
                    inputTemp2[j] += .8;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("9"))
                {
                    inputTemp2[j] += .9;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals("0"))
                {
                    inputTemp2[j] += 0;
                    inputTemp2[j] = inputTemp2[j]*10;
                }
                else if(Temporary.equals(" "))
                {
                    j++;
                }
            }
        }
        for(int j = 0; j<numHum1; j+=0)
        {
            for(int i = 0; i<hum1.length(); i++)
            {
                String Temporary = hum1.substring(i,i+1);
                if(Temporary.equals("1"))
                {
                   inputHum1[j] += .1;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("2"))
                {
                   inputHum1[j] += .2;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("3"))
                {
                   inputHum1[j] += .3;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("4"))
                {
                   inputHum1[j] += .4;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("5"))
                {
                   inputHum1[j] += .5;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("6"))
                {
                   inputHum1[j] += .6;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("7"))
                {
                   inputHum1[j] += .7;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("8"))
                {
                   inputHum1[j] += .8;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("9"))
                {
                   inputHum1[j] += .9;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals("0"))
                {
                   inputHum1[j] += 0;
                   inputHum1[j] =inputHum1[j]*10;
                }
                else if(Temporary.equals(" "))
                {
                    j++;
                }
            }
        }
        for(int j = 0; j<numHum2; j+=0)
        {
            for(int i = 0; i<hum2.length(); i++)
            {
                String Temporary = hum2.substring(i,i+1);
                if(Temporary.equals("1"))
                {
                   inputHum2[j] += .1;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("2"))
                {
                   inputHum2[j] += .2;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("3"))
                {
                   inputHum2[j] += .3;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("4"))
                {
                   inputHum2[j] += .4;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("5"))
                {
                   inputHum2[j] += .5;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("6"))
                {
                   inputHum2[j] += .6;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("7"))
                {
                   inputHum2[j] += .7;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("8"))
                {
                   inputHum2[j] += .8;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("9"))
                {
                   inputHum2[j] += .9;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals("0"))
                {
                   inputHum2[j] += 0;
                   inputHum2[j] =inputHum2[j]*10;
                }
                else if(Temporary.equals(" "))
                {
                    j++;
                }
            }
        }
    }
    
    public String temp1Method(double temp)
    {
       temp = inputTemp;
       double average = 0.0;
       double maxDeviation = 0;
       for(int i = 0; i < numTemp1; i++)
       {
           average = average + inputTemp1[i];
           if(temp - inputTemp1[i]> 0.0)
           {
               if(temp-inputTemp1[i]>maxDeviation)
               {
                   maxDeviation = temp-inputTemp1[i];
               }
           }
           if(temp - inputTemp1[i]< 0.0)
           {
               if(inputTemp1[i]-temp>maxDeviation)
               {
                   maxDeviation = inputTemp1[i]-temp;
               }
           }
       }
       average = average/numTemp1;
       if(inputTemp-.5 <= average)
       {
           if(average <= inputTemp+.5)
           {
               if(maxDeviation<3)
               {
                   return "Ultra Precise";
               }
               if(maxDeviation<5)
               {
                   return "Very Precise";
               }
           }
       }
       else
       {
           return "Precise";
       }
       return "Precise";   
    }
    
    public String temp2Method(double temp)
    {
       temp = inputTemp;
       double average = 0.0;
       double maxDeviation = 0;
       for(int i = 0; i < numTemp2; i++)
       {
           average = average + inputTemp2[i];
           if(temp - inputTemp2[i]> 0.0)
           {
               if(temp-inputTemp2[i]>maxDeviation)
               {
                   maxDeviation = temp-inputTemp2[i];
               }
           }
           if(temp - inputTemp2[i]< 0.0)
           {
               if(inputTemp2[i]-temp>maxDeviation)
               {
                   maxDeviation = inputTemp2[i]-temp;
               }
           }
       }
       average = average/numTemp2;
       if(inputTemp-.5 <= average)
       {
           if(average <= inputTemp+.5)
           {
               if(maxDeviation<3)
               {
                   return "Ultra Precise";
               }
               if(maxDeviation<5)
               {
                   return "Very Precise";
               }
           }
       }
       else
       {
           return "Precise";
       }
       return "Precise";    
    }
    public String hum1Method(double hum)
    {
       hum = inputHum;
       double lowerBound = hum * .99;
       double upperBound = hum * 1.01;
       int a = 0;
       for(int i = 0; i < numHum1; i++)
       {
           a=0;
           if(inputHum1[i] >= lowerBound)
           {
               if(upperBound >= inputHum1[i])
               {
                   a= 1;
               }
               else
               {
                   a=0;
               }
            }
       }
       if(a==1)
       {
           return "Keep";
        }
       return "Discard";    
    }
    public String hum2Method(double hum)
    {
       hum = inputHum;
       double lowerBound = hum * .99;
       double upperBound = hum * 1.01;
       int a = 0;
       for(int i = 0; i < numHum2; i++)
       {
           a=0;
           if(inputHum2[i] >= lowerBound)
           {
               if(upperBound >= inputHum2[i])
               {
                   a= 1;
               }
               else
               {
                   a=0;
               }
            }
       }
       if(a==1)
       {
           return "Keep";
       }
       return "Discard";    
    }
}
