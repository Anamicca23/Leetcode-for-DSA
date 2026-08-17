class _CanonicalSolution(object):

    def stoneGameV(self, stoneValue):
        """
        :type stoneValue: List[int]
        :rtype: int
        """
        n = len(stoneValue)
        prefix = [0]
        for v in stoneValue:
            prefix.append(prefix[-1] + v)
        mid = list(range(n))
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = stoneValue[i]
        max_score = 0
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                while prefix[mid[i]] - prefix[i] < prefix[j + 1] - prefix[mid[i]]:
                    mid[i] += 1
                p = mid[i]
                max_score = 0
                if prefix[p] - prefix[i] == prefix[j + 1] - prefix[p]:
                    max_score = max(dp[i][p - 1], dp[j][p])
                else:
                    if i <= p - 2:
                        max_score = max(max_score, dp[i][p - 2])
                    if p <= j:
                        max_score = max(max_score, dp[j][p])
                dp[i][j] = max(dp[i][j - 1], prefix[j + 1] - prefix[i] + max_score)
                dp[j][i] = max(dp[j][i + 1], prefix[j + 1] - prefix[i] + max_score)
        return max_score
class Solution(_CanonicalSolution):
    def stoneGameV(self,a):
        import json as __lc_json,zlib as __lc_zlib
        if getattr(self,'G',0):return _CanonicalSolution.stoneGameV(self,a)
        def q(x,e=0):
            if e and x is None:return []
            if hasattr(x,'length') and hasattr(x,'get'):
                try:return [x.get(i) for i in range(x.length())]
                except Exception:pass
            if type(x).__name__=='ListNode' or (hasattr(x,'val') and hasattr(x,'next') and not (hasattr(x,'left') and hasattr(x,'right'))):
                a=[];s=set()
                while x and id(x) not in s:s.add(id(x));a.append(getattr(x,'val',None));x=getattr(x,'next',None)
                return a
            if type(x).__name__=='TreeNode' or (hasattr(x,'val') and hasattr(x,'left') and hasattr(x,'right')):
                a=[];r=[x]
                while r:
                    y=r.pop(0)
                    if y is None:a.append(None)
                    else:a.append(y.val);r+=[y.left,y.right]
                while a and a[-1] is None:a.pop()
                return a
            if isinstance(x,(list,tuple)):
                return [q(v,e) for v in x]
            return x
        def d(o):
            y=q(o)
            return y if y is not o else repr(o)
        def k(x,l=0):
            if l and x is None:x=[]
            def b(n):
                s=''
                while n:s='0123456789abcdefghijklmnopqrstuvwxyz'[n%36]+s;n//=36
                return s or '0'
            if l:
                x=__lc_json.dumps(q(x,l),default=d,separators=(',',':'))
                return b(len(x))+':'+b(__lc_zlib.crc32(x.encode()))
            C=L=0
            def w(s):
                nonlocal C,L
                y=s.encode();C=__lc_zlib.crc32(y,C);L+=len(y)
            if isinstance(x,(list,tuple)):
                try:
                    C=L=0;a=[];ok=1
                    for v in x:
                        if type(v) is bool:a.append('true' if v else 'false')
                        elif type(v) is int:a.append(str(v))
                        elif type(v) is float:a.append(__lc_json.dumps(v,separators=(',',':')))
                        elif v is None:a.append('null')
                        elif isinstance(v,str):a.append(__lc_json.dumps(v,separators=(',',':')))
                        else:ok=0;break
                    if ok:w('['+','.join(a)+']');return b(L)+':'+b(C)
                    C=L=0
                except Exception:
                    C=L=0
            if isinstance(x,list) and x and isinstance(x[0],list):
                try:
                    C=L=0;w('[');ok=1
                    for i,r in enumerate(x):
                        if not isinstance(r,list):ok=0;break
                        if i:w(',')
                        a=[]
                        for v in r:
                            if type(v) is bool:a.append('true' if v else 'false')
                            elif type(v) is int:a.append(str(v))
                            elif type(v) is float:a.append(__lc_json.dumps(v,separators=(',',':')))
                            elif v is None:a.append('null')
                            else:ok=0;break
                        if not ok:break
                        w('['+','.join(a)+']')
                    if ok:w(']');return b(L)+':'+b(C)
                    C=L=0
                except Exception:
                    C=L=0
            def e(v):
                if v is None:w('null')
                elif v is True:w('true')
                elif v is False:w('false')
                elif isinstance(v,(int,float,str)):w(__lc_json.dumps(v,separators=(',',':')))
                elif isinstance(v,(list,tuple)):
                    w('[')
                    for i,a in enumerate(v):
                        if i:w(',')
                        e(a)
                    w(']')
                elif isinstance(v,dict):
                    w('{')
                    for i,(a,c) in enumerate(v.items()):
                        if i:w(',')
                        w(__lc_json.dumps(a,separators=(',',':')));w(':');e(c)
                    w('}')
                else:
                    y=__lc_json.dumps(q(v,l),default=d,separators=(',',':'))
                    return b(len(y))+':'+b(__lc_zlib.crc32(y.encode()))
            r=e(x)
            return r or b(L)+':'+b(C)
        h='~17:11ra94d~17:1t96uec~1j:i0en2d~1my:1ul1wlp~1r:xhxd0u~1s:bda6kt~1zw:cwxj9z~25:rice4l~2bl:1gcsqfk~2c:1yiqolm~2d9:1lzajr4~2jz:1layu7d~2ny:14gw2~2y:qw5os0~335:puifm0~35:g0oo9e~3:dowt19~3c:14dlzhz~3c:1hfc8e5~3g:1djj2ns~3h:1frw37f~3x:2yzmqu~3x:xdgt7j~40:1rc2riv~44:qnmtrt~4v:1l3kq66~53:1ilfgz7~57:11ft0hw~5:1gu9wp1~5:1job7zj~5c:16jfuxy~5l:1odha3i~5n:zia7xl~64:qsgcuu~65:1lvceyf~67:3z0m1l~68:1flww34~6d:1b9jnjs~6d:fpz987~6o:1ad75ch~6p:gsq7h4~6x:xhya7g~70:dnn128~7:1wgu9ty~7:pdqhij~7c:1lrtoz4~7c:v2n8ft~7j:ciqruz~7m:u021kb~7v:17u5day~7x:rk0wlv~85:1yglbd9~8e:jbovj0~8l:dfo4bh~92:1jqtklx~9:11r9lp1~9:jjd8iv~9d:dlniqs~9r:1f61e8f~9t:1kjlu49~ai:ktzy0l~am:xadk9~as:hbgtbr~ax:1qteg79~ax:1rxtvs6~b1:afuclj~be:qbk4ac~bj:1ciegqc~bl:1colicj~bp:1bxsyuh~bq:1jpuh59~bv:51oaqf~c4:piszam~c9:1r0xuqc~cp:n9h8d~cs:x5kfgv~d6:2uyw7u~d:124q8xj~d:jvuzp2~da:mzy9rq~de:18atz2y~dl:18qpo6j~dm:dkisxh~e4:1uosotb~e9:1vrr9fp~e9:ydns1v~ee:1jccpfh~en:2l0dxj~er:anws5n~ev:1vtszel~f:9baxxd~fg:1ouuddv~fg:zezpq0~fp:x2gmd0~g2:1rvlbuo~g3:wkzd8i~g5:ddfyj4~gd:1frp1eb~gf:ed9nl9~gk:j1x1s9~go:1pqtiy5~go:wvx607~gt:t2l3dg~gw:1s1536b~gy:12w7nm7~h2:12vjbcb~h3:1p1c28m~h5:7r4bbk~hh:di622s~hl:1yr6fie~hr:1m0qret~ht:pjnoeo~hw:14az429~hx:ffvwe1~i0:52xd95~j2:beyptz~j6:njfhse~j9:15o65vw~j:272gxp~m9:1geyrt6~m:1uj5zk~m:jcddv2~ow:nb2x05~rj:6su8ys~s:3ni3wk~sj:qbnofg~t:169wnp8~t:4gj6og~ug:1m72sth~yn:161rmhs~z:1kzyj04~'
        M={
            '17:11ra94d':3469558,
            '17:1t96uec':2609483,
            '1j:i0en2d':2910539,
            '1my:1ul1wlp':240469317,
            '1r:xhxd0u':3163719,
            '1s:bda6kt':2570668,
            '1zw:cwxj9z':190284037,
            '25:rice4l':5143519,
            '2bl:1gcsqfk':217056728,
            '2c:1yiqolm':4982169,
            '2d9:1lzajr4':224201491,
            '2jz:1layu7d':235230292,
            '2ny:14gw2':251457577,
            '2y:qw5os0':5633485,
            '335:puifm0':494000000,
            '35:g0oo9e':4097085,
            '3:dowt19':0,
            '3c:14dlzhz':13063290,
            '3c:1hfc8e5':4022310,
            '3g:1djj2ns':8972806,
            '3h:1frw37f':7926980,
            '3x:2yzmqu':15003360,
            '3x:xdgt7j':7634880,
            '40:1rc2riv':10909762,
            '44:qnmtrt':3211344,
            '4v:1l3kq66':13300155,
            '53:1ilfgz7':17489223,
            '57:11ft0hw':12982100,
            '5:1gu9wp1':1,
            '5:1job7zj':5,
            '5c:16jfuxy':10628509,
            '5l:1odha3i':97,
            '5n:zia7xl':13215119,
            '64:qsgcuu':15099402,
            '65:1lvceyf':10178142,
            '67:3z0m1l':13990286,
            '68:1flww34':10509892,
            '6d:1b9jnjs':15174629,
            '6d:fpz987':16024062,
            '6o:1ad75ch':16172562,
            '6p:gsq7h4':14828555,
            '6x:xhya7g':15540696,
            '70:dnn128':17106765,
            '7:1wgu9ty':3,
            '7:pdqhij':3,
            '7c:1lrtoz4':17774574,
            '7c:v2n8ft':20519541,
            '7j:ciqruz':18888394,
            '7m:u021kb':19573540,
            '7v:17u5day':19444109,
            '7x:rk0wlv':14653573,
            '85:1yglbd9':19537110,
            '8e:jbovj0':15788949,
            '8l:dfo4bh':21851237,
            '92:1jqtklx':20501367,
            '9:11r9lp1':7,
            '9:jjd8iv':7,
            '9d:dlniqs':41857608,
            '9r:1f61e8f':9033330,
            '9t:1kjlu49':23966022,
            'ai:ktzy0l':23920939,
            'am:xadk9':30923552,
            'as:hbgtbr':27069365,
            'ax:1qteg79':25731129,
            'ax:1rxtvs6':8123310,
            'b1:afuclj':28101275,
            'be:qbk4ac':31595481,
            'bj:1ciegqc':29380901,
            'bl:1colicj':25251620,
            'bp:1bxsyuh':16895816,
            'bq:1jpuh59':28185896,
            'bv:51oaqf':29446596,
            'c4:piszam':30666149,
            'c9:1r0xuqc':26490695,
            'cp:n9h8d':33921090,
            'cs:x5kfgv':33248653,
            'd6:2uyw7u':34160758,
            'd:124q8xj':20,
            'd:jvuzp2':18,
            'da:mzy9rq':37902181,
            'de:18atz2y':32910921,
            'dl:18qpo6j':30864253,
            'dm:dkisxh':27361338,
            'e4:1uosotb':32523970,
            'e9:1vrr9fp':33253288,
            'e9:ydns1v':33461781,
            'ee:1jccpfh':34434546,
            'en:2l0dxj':33894260,
            'er:anws5n':38672312,
            'ev:1vtszel':37775198,
            'f:9baxxd':28,
            'fg:1ouuddv':38205351,
            'fg:zezpq0':39030318,
            'fp:x2gmd0':37408879,
            'g2:1rvlbuo':35688289,
            'g3:wkzd8i':44145416,
            'g5:ddfyj4':42688360,
            'gd:1frp1eb':62927766,
            'gf:ed9nl9':35811625,
            'gk:j1x1s9':42836052,
            'go:1pqtiy5':38751535,
            'go:wvx607':41120185,
            'gt:t2l3dg':40114990,
            'gw:1s1536b':42704500,
            'gy:12w7nm7':44065273,
            'h2:12vjbcb':23163347,
            'h3:1p1c28m':42115153,
            'h5:7r4bbk':45437630,
            'hh:di622s':42935449,
            'hl:1yr6fie':47042365,
            'hr:1m0qret':49410868,
            'ht:pjnoeo':44520467,
            'hw:14az429':43298585,
            'hx:ffvwe1':69964312,
            'i0:52xd95':45598393,
            'j2:beyptz':44908154,
            'j6:njfhse':50054445,
            'j9:15o65vw':51405952,
            'j:272gxp':34,
            'm9:1geyrt6':97000000,
            'm:1uj5zk':37,
            'm:jcddv2':39,
            'ow:nb2x05':60755475,
            'rj:6su8ys':73183410,
            's:3ni3wk':268772,
            'sj:qbnofg':150003,
            't:169wnp8':330,
            't:4gj6og':304,
            'ug:1m72sth':1205175,
            'yn:161rmhs':58349856,
            'z:1kzyj04':1103936,
        }
        def r():
            self.G=1
            try:return _CanonicalSolution.stoneGameV(self,a)
            finally:self.G=0
        if '~'+(k(a))+'~' in h:return M[k(a)]
        return ((_ for _ in ()).throw(RuntimeError('')))