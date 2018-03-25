# coding:utf-8
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import time
'''
    class Brick();
        find the max usege of raw brick
'''

class Brick():
    '''
        brick_list saves the length and width of all the bricks as a dictionary. 
            example:
            d = {1:[4, 6], 2:[3,2], 3:[1,1]} there are three types of bricks, as the length and width in d[1], d[2], d[3]
        raw_material saves the length and width of the raw material as a list
            example:
                [100, 100] the length and width of the raw material is 100 and 100
        bricknums is the sum types of the bricks
        result save the max usage plan
            example:
                dic = { 'info':[usage, usedarea, fullarea], 'size':[x1, x2, y1, y1], 
                'nextone':{
                    'info':[usage, usedarea, fullarea], 'size':[x1, x2, y1, y1], 'nextone':{......},'nexttwo':{......}
                }, 'nexttwo':{
                    'info':[usage, usedarea, fullarea], 'size':[x1, x2, y1, y1], 'nextone':{......},'nexttwo':{......}
                }
                }
            info: usage is use ratio of the bricks, usearea is area of the useful bricks, fullarea is calculate by (x2 - x1)*(y2 - y1)
            size: there are four coordinates , x1 x2 is the absciass, y1 y2 is the ordinate.
            nextone: one of the brick cut by knife
            nexttwo: another brick cut by knife
        result_point save the coordinates of all the found bricks
            example:
                we find two bricks contented and the coordinates are [0, 1, 0, 1], [1, 2, 0, 1], .........
                so the result_point is [[0, 1, 0, 1], [1, 2, 0, 1], [.........]]
    '''
    def __init__(self, raw_material, bricknums, brick_list, result, result_point):
        self.raw_material = raw_material
        self.bricknums = bricknums
        self.brick_list = brick_list
        self.result = result
        self.result_point = result_point


    '''
        inputBrickInfo():  input the infomation of the raw material and all types of the cut-bricks
    '''
    def inputBrickInfo(self):
        leng = 88
        print leng*'*'
        self.raw_material = input('请输入原材料的规格（长和宽）:')
        self.bricknums = input('请输入要切割的砖头种类总数:')
        for i in range(1, self.bricknums + 1):
            brick_list[i] = list(input('请输入第 {} 种砖块的规格(长和宽):'.format(i)))

    '''
        sortBrickSize(): sort the bricks from large size to small size
            example:
                the brick_list is {1:[1, 1], 2:[3, 4], 3:[5, 6]}
                after finishing this function, we get the brick_list:
                    {1:[5, 6], 2:[3, 4], 3:[1, 1]}
    '''
    def sortBrickSize(self):
        temp_list = ()
        for i in range(1, self.bricknums + 1):
            max_area = self.brick_list[i][0] * self.brick_list[i][1]
            target = 0
            for j in range(i + 1, self.bricknums + 1):
                if max_area < self.brick_list[j][0] * self.brick_list[j][1]:
                    target = j
                    max_area = self.brick_list[j][0] * self.brick_list[j][1]
            if target:
                self.brick_list[target], self.brick_list[i] = self.brick_list[i], self.brick_list[target]
    '''
        findContentBrick():
            judge whether the brick now is accored with one of the given bricks in self.brick_list
            if it contents, the usage change to 1
    '''
    def findContentBrick(self, x1, x2, y1, y2):
        side_length = [x2 - x1, y2 - y1]
        for i in range(1, self.bricknums + 1):
            # find it
            if side_length == self.brick_list[i]:
                return 1
        return 0


    '''
        calArea(): return the area of the brick
    '''
    def calArea(self, x1, x2, y1, y2):
        return (x2 - x1)*(y2 - y1)


    '''
        updateInfo(): update the dict['info'][0] (usage), dict['info'][1] (usedarea)
    '''
    def updateInfo(self, usedarea, dict, fullarea):
        dict['info'][0] = (float)(usedarea) / (float)(fullarea)
        dict['info'][1] = usedarea

    '''
        replaceArrayxy():replace the xy matrix from (x1, y1) to (y1, y2) 
            example:
                wo got xy [[0, 0],
                            [0, 0]]
                then replaceArrayxy(xy, 0, 0, 1, 1, 5)
                we got xy [[5, 5],
                            [5, 5]]
    '''

    def replaceArrayxy(self, xy, x1, x2, y1, y2, val):
        for i in range(x1, x2):
            for j in range(y1, y2):
                xy.itemset((j, i), val)
    '''
        plotGraph(): using matplotlib and numpy to draw the result of the bricks we just cut
    '''
    def plotGraph(self):
        fig = plt.figure()
        ax = fig.add_subplot(111)
        xy = np.zeros([self.raw_material[1], self.raw_material[0]])
        countlist = {}
        for i in range(1, len(self.brick_list) + 1):
            countlist[i] = 0
        for i in self.result_point:
            l = [i[1] - i[0], i[3] - i[2]]
            for j in range(1, len(self.brick_list) + 1):
                if l == self.brick_list[j]:
                    countlist[j] += 1
                    self.replaceArrayxy(xy, i[0], i[1], i[2], i[3], j)
        leng = 88
        print leng*'-'
        for j in range(1, len(self.brick_list) + 1):
            print '大小为{0}的石块颜色对应的序号为{1}, 个数为{2}'.format(self.brick_list[j], j, countlist[j])
        print '利用率为{0:.2%}, 利用面积为{1}, 原材料总面积为{2}'.format((float)(self.result['info'][0]), self.result['info'][1], self.result['info'][2])
        print leng*'*'
        plt.imshow(xy)
        plt.colorbar() 
        plt.show()

        


    '''
        getResult(): get the result_point through dictionary result
    '''
    def getResult(self, dict, blank):
        # print '-'*blank, 'info:', dict['info']
        # print '-'*blank, 'size', dict['size']
        # print '*********************************'
        if dict['nextone']:
            self.getResult(dict['nextone'], blank + 4)
        if dict['nexttwo']:
            self.getResult(dict['nexttwo'], blank + 4)
        if dict['nextone'] == {} and dict['nexttwo'] == {} and dict['info'][0] == 1:
            self.result_point.append(dict['size'])

    '''
        findOptimalSolution():
            its function is just like the name it is. through this function, we try all the probability to find the optimal solution
    '''
    def findOptimalSolution(self, x1, x2, y1, y2, resdic):
        resdic['size'] = [x1, x2, y1, y2]
        resdic['nextone'] = {}
        resdic['nexttwo'] = {}
        resdic['info'] = [0, 0, self.calArea(x1, x2, y1, y2)]
        # judge if it is accorded with one of the given bricks in self.brick_list
        if self.findContentBrick(x1, x2, y1, y2):
            resdic['info'] = [1.0, self.calArea(x1, x2, y1, y2), self.calArea(x1, x2, y1, y2)]    
            return 0

        for i in range(1, self.bricknums + 1):
            max = 0
            '''
                across cutting
            '''
            if x1 + self.brick_list[i][0] < x2:
                dic1 = {'info':[], 'size':[], 'nextone':{}, 'nexttwo':{}}
                dic2 = {'info':[], 'size':[], 'nextone':{}, 'nexttwo':{}}
                self.findOptimalSolution(x1, x1 + self.brick_list[i][0], y1, y2, dic1)
                self.findOptimalSolution(x1 + self.brick_list[i][0], x2, y1, y2, dic2)
                # find out a more useful result
                usedarea = dic1['info'][1] + dic2['info'][1]
                if usedarea > resdic['info'][1]:
                    self.updateInfo(usedarea, resdic, self.calArea(x1, x2, y1, y2))
                    resdic['nextone'] = dic1
                    resdic['nexttwo'] = dic2
            '''
                rip cutting
            '''
            if y1 + self.brick_list[i][1] < y2:
                dic1 = {'info':[], 'size':[], 'nextone':{}, 'nexttwo':{}}
                dic2 = {'info':[], 'size':[], 'nextone':{}, 'nexttwo':{}}
                self.findOptimalSolution(x1, x2, y1, y1 + self.brick_list[i][1], dic1)
                self.findOptimalSolution(x1, x2, y1 + self.brick_list[i][1], y2, dic2)
                usedarea = dic1['info'][1] + dic2['info'][1]
                if usedarea > resdic['info'][1]:
                    self.updateInfo(usedarea, resdic, self.calArea(x1, x2, y1, y2))
                    resdic['nextone'] = dic1
                    resdic['nexttwo'] = dic2

if __name__ == '__main__':
    #initialize the property of the living example
    raw_material = []
    brick_list = {}
    bricknums = 0
    result = {'info':[], 'size':[], 'nextone':{}, 'nexttwo':{}}
    result_point = []

    brick = Brick(raw_material, bricknums, brick_list, result, result_point)
    brick.inputBrickInfo()

    time_start = time.time()

    brick.sortBrickSize()
    brick.findOptimalSolution(0, brick.raw_material[0], 0, brick.raw_material[1], brick.result)
    brick.getResult(brick.result, 0)
    time_end = time.time()
    print '找到结果'
    print '用时:{0:.3f}s'.format(time_end - time_start)
    print brick.result_point
    brick.plotGraph()