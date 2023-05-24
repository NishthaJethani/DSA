class Set:

    def __init__(self, n):
        self.s=[]
        for i in range(n):
            e=int(input("Enter Element {}:" .format(i+1)))
            self.add(e)

    def __len__(self):
        return len(self.s)
    
    def __str__(self):
        string="\n{ "
        for i in range(len(self)):
            string+=str(self.s[i])
            if i!=len(self.s)-1:
                string+=" , "
        string+=" }\n"
        return string
    
    def __contains__(self, e):
        return e in self.s
    
    def __iter__(self):
        return iter(self.s)
        
    def add(self, e):
        if e not in self.s:
            self.s.append(e)

    def remove(self, e):
        if e in self.s:
            self.s.remove(e)
    
    def search(self, e):
        if e in self.s:
            print("Present in Set.")
        else:
            print("Not present in Set.")

    def intersect(self, r):
        t=Set(0)
        for i in range(len(self)):
            for j in range(len(r)):
                if self.s[i]==r.s[j]:
                    t.add(self.s[i])
        return t
    
    def union(self, r):
        t=self
        for i in r.s:
            if i not in self.s:
                t.add(i)
        return t
    
    def difference(self, r):
        t=Set(0)
        for i in self.s:
            if i not in r.s:
                t.add(i)
        return t
    
    def subset(self, r):
        for i in r.s:
            if i not in self.s:
                return False
        return True
    
    def properSubset(self, r):
        if self.subset(r) and not r.subset(self):
            return True
        return False


def main():

    n=int(input("Enter number of elements in set: "))
    s=Set(n)
    print(s)

    while (1):
        print("\n1. Add element in set")
        print("2. Remove element from set")
        print("3. Check if element is in set")
        print("4. Size of set")
        print("5. Intersection of two sets")
        print("6. Union of two sets")
        print("7. Difference of two sets")
        print("8. Check if a set is a subset of another set")
        print("9. Check if a set is a proper subset of another set")
        print("10. Exit")
        choice=int(input("Enter choice:"))

        if choice==1:
            e=int(input("Enter element to add: "))
            s.add(e)
            print(s)

        if choice==2:
            e=int(input("Enter element to remove: "))
            s.remove(e)
            print(s)

        if choice==3:
            e=int(input("Enter element to search for: "))
            s.search(e)
            
        if choice==4:
            print("Set contains {} elements".format(len(s)))

        if choice==5:
            print("Create a set B to intersect with")
            n=int(input("Enter number of elements in set: "))
            r=Set(n)
            t=s.intersect(r)
            print("Set A = "+str(s))
            print("Set B = "+str(r))
            print("Intersection = "+str(t))

        if choice==6:
            print("Create a set B to make union with")
            n=int(input("Enter number of elements in set: "))
            r=Set(n)
            t=s.union(r)
            print("Set A = "+str(s))
            print("Set B = "+str(r))
            print("Union = "+str(t))

        if choice==7:
            print("Create a set B to calculate difference")
            n=int(input("Enter number of elements in set: "))
            r=Set(n)
            t=s.difference(r)
            print("Set A = "+str(s))
            print("Set B = "+str(r))
            print("Difference = "+str(t))

        if choice==8:
            print("Create a set B to check if it is a subset of A")
            n=int(input("Enter number of elements in set: "))
            r=Set(n)
            print("Set A = "+str(s))
            print("Set B = "+str(r))
            t=s.subset(r)
            if t:
               print("Set B is a subset of Set A")
            else:
                print("Set B is not subset of A")


        if choice==9:
            print("Create a set B to check if it is a proper subset of A")
            n=int(input("Enter number of elements in set: "))
            r=Set(n)
            print("Set A = "+str(s))
            print("Set B = "+str(r))
            t=s.properSubset(r)
            if t:
               print("Set B is a proper subset of Set A")
            else:
                print("Set B is not proper subset of A")

        if choice==10:
            exit()

main()