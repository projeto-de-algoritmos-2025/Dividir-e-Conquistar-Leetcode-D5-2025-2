class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return lists
        
        if len(lists) == 1:
            return lists[0]

        metade = len(lists) // 2
        esquerda = lists[:metade]
        direita = lists[metade:]
        
        esquerda_ordenada = self.mergeKLists(esquerda)
        direita_ordenada = self.mergeKLists(direita)

        return self.merge(esquerda_ordenada, direita_ordenada)
    
    def merge(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        lista = ListNode()
        aux = lista

        while l1 and l2:
            if l1.val < l2.val:
                aux.next = l1
                l1 = l1.next
            else:
                aux.next = l2
                l2 = l2.next
            aux = aux.next

        if l1:
            aux.next = l1
        elif l2:
            aux.next = l2
            
        return lista.next