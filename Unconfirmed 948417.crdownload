from pandas import DataFrame , read_csv

class Subject (object):
    """Subject class"""
    def __init__ (self, sub_code, sub_name, sub_pre= '', cre_pre= 0, sub_cre= 0):
        """ Subject constructor.
        
        :param sub_code: subject code           : str - PRIMARY KEY
        :param sub_name: subject name           : str
        :param sub_pre : subject-prerequisite   : str
        :param cre_pre : credit -prerequisite   : int
        :param sub_cre : the number of credits  : int
        """
        self.sub_code = sub_code
        self.sub_name = sub_name
        self.sub_pre  = sub_pre
        self.cre_pre  = cre_pre
        self.sub_cre  = sub_cre 
    
    def getName (self):
        """ Get name of subject """
        return self.sub_name
    
    def getCode (self):
        """ Get code of subject """
        return self.sub_code

    def getSub_pre(self):
        """ Get subject-prerequisite """
        return self.sub_pre 

    def getCredits (self):
        """ Get the number of credits of subject"""
        return self.sub_cre

    def getData(self):
        """ Get array data of subject"""
        return [self.sub_code, self.sub_name, self.sub_pre, self.cre_pre, self.sub_cre]
    
    def setName (self, new_name):
        """ Set name of subject """
        self.sub_name = new_name

    def setCode (self, new_code):
        """ Set code of subject """
        self.sub_code = new_code

    def setSub_pre(self, new_pre):
        """ Set subject-prerequisite """
        self.sub_pre = new_pre

    def setCredits (self, new_cre):
        """ Set the number of credits of subject"""
        self.sub_cre = new_cre


class SubjectCatalog (object):
    """Subject catalog class"""
    def __init__( self , subs = []):
        """ Subject Catalog constructor
        
        :prama subs     : list of subjects - standard
        :prama code_dict: dictionary subject code
        """
        self.subs = subs
        self.code_dict = dict()
        for i in range(len(self.subs)):
            self.code_dict[subs[i].getCode()] = i    

    @staticmethod
    def isNaN (x):
        """ check NaN """
        return x != x
    
    @staticmethod
    def toDataFrame (subs = None):
        """ Create DataFram

        :prama subs: list of subject
        """
        Col = ['STT', 'Mã môn', 'Tên môn', 'HP tiên quyết', 'TC tiên quyết', 'Số TC']
        data= []
        for i in range(len(subs)):
            data.append([i + 1] + subs[i].getData())
        return DataFrame(data, columns = Col)

    def readCSV(self, f_name):
        """ Read data from file - CSV

        :prama f_name: file name
        """
        self.subs = []
        data = read_csv(f_name)
        for i in range(len(data)):
            sub = data.iloc[i,:].values
            s = Subject(sub[1],sub[2],'' if self.isNaN(sub[3]) else sub[3], 0 if self.isNaN(sub[4]) else int(sub[4]),int(sub[5]))
            self.subs.append(s)
            self.code_dict[s.getCode()] = self.size()
        print("Đã tải lên " + str(len(self.subs)) + " môn học.")

    def saveCSV(self, f_name, subs = None):
        """ Write data in file - CSV

        ::prama f_name: file name
        """
        if subs == None:
            subs = self.subs
        self.toDataFrame(subs).to_csv(f_name, index = None, header=True)
        print("Đã lưu !")

    def getDataFrame(self):
        """ Get dataframe - pandas"""
        return self.toDataFrame(self.subs)

    def show (self, subs = None):
        """ Show subjects """
        if subs == None:
            subs = self.subs
        #print(self.toDataFrame(subs))
        return self.toDataFrame(subs)
        
    def size (self):
        """ Take the number of subjects """
        return len(self.subs)

    def is_valid (self, sub : Subject, code = None):
        """ Check valid
        
        :prama sub: subject
        """
        if sub.getCode() != code and self.code_dict.get(sub.getCode(), 0) != 0:
            print("Lỗi: Mã môn học đã tồn tại !")
            return False

        pre = sub.getSub_pre().split(', ')
        for p in pre:
            if p != '' and self.code_dict.get(p, 0) == 0:
                print("Cảnh báo: \'" + p + "\' không tồn tại !")
        
        return True

    def add (self, sub : Subject):
        """ Add a new subject to list
        
        :prama sub: subject
        """
        if not self.is_valid(sub):
            return False
        self.subs.append(sub)
        self.code_dict[sub.getCode()] = self.size()
        print("Đã thêm mới một môn học !")
        return True
    
    def get_id (self, sub_code):
        """ Take the index of a subject in list - (1..n)

        :prama sub_code: code of subject
        """
        return self.code_dict.get(sub_code, 0)

    def update (self,id, sub : Subject):
        """ Update subject 
        
        :prama id : the index of subject
        :prama sub: new update of subject
        """
        if self.is_valid(sub, self.subs[id-1].getCode()):
            self.subs[id-1] = sub
            print("Đã cập nhập thông tin môn học !")
        
    
    def remove(self, id = None, code = None):
        """ remove subject
        
        :prama id  : the index of subject
        :prama code: the code of subject
        """
        if code != None:
            id = self.get_id(code)
        if id <= 0 or id > self.size():
            return
        subname = self.subs[id-1].getName() 
        for i in range(id-1, self.size() -1):
            self.subs[i] = self.subs[i+1]
            self.code_dict[self.subs[i].getCode()] = i+1 #Update dict
        self.subs.pop()
        print("Đã xóa môn học " + subname + " !")

    def find(self, key = None, credits= None):
        """ find subject by name, code or credits of subject

        :prama key    : name or code of subject - string
        :prama credits: credits of subject - int
        """
        r = []
        if key != None:
            key = key.lower()
            for s in self.subs:
                if key in s.getCode().lower() or key in s.getName().lower():
                    r.append(s)
        if credits != None:
            for s in self.subs:
                if credits == s.getCredits():
                    r.append(s)
        return SubjectCatalog(r)

    def sort_by(self, s):
        """ Sort subjects by key 's'

        :prama s: string ("name" , "code" or "credits")
        """
        s = s.lower()
        t_subs = self.subs
        if s == 'code':
            t_subs.sort(key = Subject.getCode)
        if s == 'name':
            t_subs.sort(key = Subject.getName)
        if s == 'credits':
            t_subs.sort(key = Subject.getCredits)
        return SubjectCatalog(t_subs)

    def getSubject(self, id):
        """ Get id_th subject 
        :prama id: index - int
        """
        if id > self.size() or id < 1 :
            return None
        return self.subs[id-1]