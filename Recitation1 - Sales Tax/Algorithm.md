## Recitation 1 Algorithm
1. Declare Variables
2. Prompt user for the **selling price** of the item. 
3.  Determine whether the item is a  
**luxury item**.  
4.  Find the **luxury tax**:  
`if (luxury) luxuryTax = salePrice * 0.1  `
5.  Find the state’s portion of the sales  
tax: `stateSalesTax = salePrice * 0.04  `
6.  Find the city’s portion of the sales  
tax: `citySalesTax = salePrice * 0.015`  
9  
7.  Find total sales tax:  
`salesTax = stateSalesTax +  citySalesTax + luxuryTax  `
8.  Finally, find amount due:  
`amountDue = salePrice + saleTax`