class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        ultimo_esquerda = head
        proximo_esquerda = head.next
        while proximo_esquerda and proximo_esquerda.next:
            ultimo_esquerda = ultimo_esquerda.next
            proximo_esquerda = proximo_esquerda.next.next
            
        metade = ultimo_esquerda.next
        ultimo_esquerda.next = None
        esquerda = self.sortList(head)
        direita = self.sortList(metade)

        return self.merge(esquerda, direita)
    
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